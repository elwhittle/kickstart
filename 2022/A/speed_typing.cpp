    #include <iostream> // includes cin to read from stdin and cout to write to stdout
    #include <string>   // includes string to cin strings
    using namespace std; // since cin and cout are both in namespace std, this saves some text
    

    string speed_typing(const string& I, const string& P) {
        if (P.size() < I.size()) { return "IMPOSSIBLE"; }
        int count = 0;
        // find I in P, then subtract difference
        size_t consistent = 0; // keeps track of place in I
        for (int i = 0; i < P.size(); ++i) {
            if (consistent == I.size()) { return to_string(P.size() - I.size()); }
            if (P[i] != I[consistent]) { ++count; }
            else ++consistent;
        }
        if (consistent == I.size()) { return to_string(count); }
        return "IMPOSSIBLE";
    }

    int main() {
      int t;
      string n, m;
      cin >> t; // read t. cin knows that t is an int, so it reads it as such.
      for (int i = 1; i <= t; ++i) {
        cin >> n >> m; // read n and then m.
        cout << "Case #" << i << ": " << speed_typing(n, m) << endl;
        // cout knows that n + m and n * m are ints, and prints them accordingly.
        // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
      }
      return 0;
    }
    