/* redone after viewing analysis */
#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <string>
using namespace std; // since cin and cout are both in namespace std, this saves some text

void challenge_nine(string& s) {
  long int sum = 0;
  for (char c : s) { sum += c - '0'; }
  int to_insert = 9 - (sum % 9);
  if (to_insert == 9) { // edge case: digit should be 0
    s.insert(1, "0");
    return;
  }
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] - '0' > to_insert) {
        s.insert(i, to_string(to_insert));
        return;
    }
  }
  // edge case: need to put new digit at last position
  s.insert(s.size(), to_string(to_insert));
}

int main() {
  int t;
  string s;
  cin >> t; // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    cin >> s; // read s.
    challenge_nine(s); // insert digit into s
    cout << "Case #" << i << ": " << s << endl;
  }
  return 0;
}