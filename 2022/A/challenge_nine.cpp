#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // since cin and cout are both in namespace std, this saves some text

int challenge_nine(const string& N) {
  vector<int> contestants;
  make_heap(contestants.begin(), contestants.end(), greater<int>());
  string test = N;
  int result = 0;
  bool has_solution = false;
  for (size_t i = 0; i <= N.size(); ++i) {
      for (int chr = 0; chr <= 9; ++chr) {
        if (chr == 0 && i == 0) continue;
        test.insert(i, to_string(chr));
        // cout << "trying " << test << endl;
        if (stoi(test) % 9 == 0) {
          if (!has_solution) { 
              result = stoi(test);
              has_solution = true; 
            } else {
              if (abs(stoi(test)) < abs(result)) result = stoi(test);
            }
        }
        test = N;
      }
  }
  return result;
}

int main() {
  int t;
  string n;
  cin >> t; // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    cin >> n; // read n and then m.
    cout << "Case #" << i << ": " << challenge_nine(n) << endl;
  }
  return 0;
}