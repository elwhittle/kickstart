/*
g++ Solution.cc -std=c++17 -pthread -O2 -o Solution
./Solution 
*/

#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text
int main() {
    int t, n, m;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
    cin >> n >> m; // read n and then m.
    cout << "Case #" << i << ": " << (n + m) << " " << (n * m) << endl;
    // cout knows that n + m and n * m are ints, and prints them accordingly.
    // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
    }
    return 0;
}
