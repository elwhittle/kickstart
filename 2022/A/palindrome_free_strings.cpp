/*
*
* 
*
*/

#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <string>
#include <algorithm>
#include <vector>
using namespace std; // since cin and cout are both in namespace std, this saves some text

// counts number of specified char in string
vector<int> char_positions(const string& s, char c) {
  vector<int> places;
  for (size_t i = 0; i < s.length(); ++i) {
    if (s[i] == c) { places.push_back(i); }
  }
  return places;
}

void add_attempts(vector<string>* attempts, int num_qs, const vector<int>& positions, string attempt) {
    if (num_qs == 0) attempts->push_back(attempt);
    else {
        // look for first '?' and replace with '1' and '0'
        int p = positions[positions.length() - num_qs - 1]
        attempt[p] = '0';

        attempt[p] = '1';
    }
}

// gets permutations based on number of strings
vector<string>* get_attempts(const string& s) {
  int num_qs = count_chars(s, '?');
  vector<string>* attempts = new vector<string>();
  add_attempts(attempts, num_qs, s);
  return attempts;
}

// reverses string. From GeeksforGeeks
void reverse_str(string& str)
{
    int n = str.length();
  
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

// counts longest common subsequence between two strings
int lcs(const string& p, const string& q) {
  int arr[p.size()][q.size()];
  // L(i, j) = if P[i] = Q[j]: 1 + L(i-1, j-1)
  //   if P[i]!= Q[j]: max(L(i-1,j), L(i, j-1))
  for (size_t i = 0; i < p.size(); ++i) {
      for (size_t j = 0; j < q.size(); ++j) {
        if (p[i] == q[j]) { // if characters are equal
          if (i == 0 || j == 0) arr[i][j] = 1;
          else arr[i][j] = 1 + arr[i-1][j-1]; 
        } else { // else keep max of previous
          if (i == 0 && j == 0) arr[i][j] = 0;
          else if (i == 0) arr[i][j] = arr[i][j-1];
          else if (j == 0) arr[i][j] = arr[i-1][j];
          else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
      }
  }
  return arr[p.size()-1][q.size()-1];
}

// determine whether there are palindrome-free strings
bool palindrome_free_strings(const string& S) {
  if (S.length() < 5) return true;

  vector<string>* attempts = get_attempts(S);
  for (const string& attempt : *attempts) {
    string reverse_attempt = attempt;
    reverse_str(reverse_attempt);
    if (lcs(attempt, reverse_attempt) < 5) {
        delete attempts;
        return true;
    }
  }
  delete attempts;
  return false;
}

int main() {
    // maybe faster with bits? no time to explore this thought though
//   int t, n;
//   string s;
//   cin >> t; // read t. cin knows that t is an int, so it reads it as such.
//   for (int i = 1; i <= t; ++i) {
//     cin >> n >> s; // read n and then s.
//     cout << "Case #" << i << ": " 
//     << (palindrome_free_strings(n, s) ? "POSSIBLE" : "IMPOSSIBLE") 
//     << " " << endl;
//   }
  return 0;
}