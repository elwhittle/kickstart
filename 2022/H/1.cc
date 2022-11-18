#include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>

using namespace std;

long long solution(long long l, int n) { 
  char dir = 'C';
  long long x, dist = 0, laps = 0;
  char newDir;
  for (int i = 0; i < n; ++i) {
    cin >> x >> newDir;
    if (newDir == dir) {
      dist += x;
    } else {
      dist -= x;
      if (dist <= 0) {
        dir = newDir;
        dist = -dist;
      }
    }
    laps += dist / l;
    dist %= l;
  }
  return laps; 
}

int main() {
  int t, n;
  long long l;
  cin >> t; // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    cin >> l >> n;
    cout << "Case #" << i << ": " << solution(l, n) << endl;
  }
  return 0;
}