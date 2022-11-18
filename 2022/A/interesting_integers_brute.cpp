#include <iostream>
#include <string>

using namespace std;

long long interesting_integers(long long n, long long m) {
  // brute force method
  long long count = 0;
  for (long long i = n; i <= m; ++i) {
    long long sum = 0;
    long long prod = 1;
    for (long long j = i; j != 0; j/=10) {
      sum += j % 10;
      prod *= j % 10;
      if (prod == 0) { break; }
    }
    if (prod % sum == 0) ++count;
  }
  return count;
}

int main() {
  int t;
  long long n, m;
  cin >> t; // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    cin >> n >> m;
    cout << "Case #" << i << ": " << interesting_integers(n, m) << endl;
  }
  return 0;
}