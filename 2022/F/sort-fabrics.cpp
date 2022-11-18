/*
g++ Solution.cc -std=c++17 -pthread -O2 -o Solution
./Solution 
*/

#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <algorithm>

using namespace std; // since cin and cout are both in namespace std, this saves some text

void sort_n(vector<pair<string, int>>& c) {
    sort(c.begin(), c.end(),
        [](const pair<string, int>& a, const pair<string,int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    );
}
void sort_d(vector<pair<int,int>>& d) {
        sort(d.begin(), d.end(),
        [](const pair<int, int>& a, const pair<int,int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    );
}

int sort_fabrics(vector<pair<string,int>>& c, vector<pair<int, int>>& d) {
    sort_n(c);
    sort_d(d);
    int count = 0;
    for (size_t i=0; i<c.size(); ++i) {
        if (c[i].second == d[i].second) {++count;}
    }
    return count;
}

int main() {
    int t, n, m;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        vector<pair<string, int>> c;
        vector<pair<int, int>> d;
        string c_name;
        int d_name, u;
        for (size_t j = 0; j < n; ++j) {
            // add to list
            cin >> c_name >> d_name >> u;
            c.push_back(make_pair(c_name, u));
            d.push_back(make_pair(d_name, u));
        }
        cout << "Case #" << i << ": " << sort_fabrics(c, d) << endl;
        // cout knows that n + m and n * m are ints, and prints them accordingly.
        // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
    }
    return 0;
}
