/*
g++ Solution.cc -std=c++17 -pthread -O2 -o Solution
./Solution 
*/

#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <algorithm>

using namespace std; // since cin and cout are both in namespace std, this saves some text

#define MAX_DEPTH 10000

struct container {
    bool marked;
    vector<container*> ns;

    container() : marked(false) {}
};

int layers[MAX_DEPTH];

void connect(container* a, container* b) { 
    if (find((a->ns).begin(), (a->ns).end(), b) == a->ns.end()) {
        (a->ns).push_back(b);
    }
}

void fillLayers(container* n, int l) {
    n->marked = true;
    layers[l]++;
    for (container* c : n->ns) {
        if (!c->marked) fillLayers(c, l+1);
    }

}

int f(int n, int q) {
    int i;
    int total = 0;
    for (i = 0; i < n; ++i) {
        q -= layers[i];
        if (q < 0) { break; }
        total += layers[i];
    }
    return total;
}

int main() {
    int t, n, q;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {

        cin >> n >> q; // read n and then q.
        for (size_t i=0; i < n; ++i) { layers[i] = 0; }

        vector<container*> nodes;
        for (int i = 0; i < n; ++i) {
            nodes.push_back(new container());
        }

        int a, b;
        // next (n-1) lines: connect i and j
        for (size_t i = 1; i <= n-1; ++i) {
            cin >> a >> b;
            connect(nodes[a-1], nodes[b-1]);
            connect(nodes[b-1], nodes[a-1]);
            // cout << endl;
        }

        fillLayers(nodes[0], 0);

        // next q lines: fill containers
        for (size_t i = 1; i <= q; ++i) {
            cin >> a;
        }

        cout << "Case #" << i << ": " << f(n, q) << endl;

        for (int i = 0; i < n; ++i) {
            delete nodes[i];
        }

    }
    return 0;
}
