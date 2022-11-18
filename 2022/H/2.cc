#include <iostream>
// #include <vector>
// #include <string>

using namespace std;

int solution(int n, int m) { 

  return 0; 
}

int main() {
  int t, n, m;
  cin >> t; // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    cin >> n >> m;
    cout << "Case #" << i << ": " << solution(n, m) << " " << (n * m) << endl;
  }
  return 0;
}