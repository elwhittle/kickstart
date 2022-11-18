/*
g++ Solution.cc -std=c++17 -pthread -O2 -o Solution
./Solution 
*/

#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>

using namespace std; // since cin and cout are both in namespace std, this saves some text

// struct node {
//     node * parent = nullptr;
//     node * left = nullptr;
//     node * right = nullptr;
// };

// void connect(node* p, node* c) {
//     if (p->left == nullptr) {
//         p-> left = c;
//     } else {p->right = c;}
//     c->parent = p;
// }

int f(int n, int q) {
    if (q >= n) { return n; }

    int i = 1;
    while (i<<1 < q) {
        i = i<<1;
    }
    return i < n ? i : n;
}

int main() {
    int t, n, q;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> q; // read n and then q.


        // vector<node*> nodes;
        // for (int i = 0; i < n; ++i) {
        //     nodes.push_back(new node());
        // }
        int a, b;
        // next (n-1) lines: connect i and j
        for (size_t i = 1; i <= n-1; ++i) {
            cin >> a >> b;
        }
        // next q lines: fill containers
        for (size_t i = 1; i <= q; ++i) {
            cin >> a;
        }

        cout << "Case #" << i << ": " << f(n, q) << endl;
        // cout knows that n + m and n * m are ints, and prints them accordingly.
        // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
        // for (int i = 0; i < n; ++i) {
        //     delete nodes[i];
        // }
    }
    return 0;
}
