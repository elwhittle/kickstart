#include <iostream>
#include <string>

#define MAX_N 1000000000000
#define MEM_SIZE 1000
#define COUNT_INCR 10000
#define MAX_COUNT MAX_N / COUNT_INCR

// 10^12
using namespace std;

long long sums[MEM_SIZE];
long long prods[MEM_SIZE];
long long counts[MAX_COUNT];
long long counts_size;

// returns the sum of digits
long long digit_sum(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += sums[n%MEM_SIZE];
    n /= MEM_SIZE;
  }
  // cout << "sum: " << sum << endl; // TODO delete
  return sum;
}

// returns the product of digits
long long digit_prod(long long n) {
  long long prod = 1;
  while (n > 0) {
    prod *= prods[n%MEM_SIZE];
    n /= MEM_SIZE;
  }
  // cout << "prod: " << prod << endl; // TODO delete
  return prod;  
}

// counts interesting integers from 0 to n
long long count_interesting_integers(long long n) {
  if (n <= 0) { return 0; }
  long long tracker = 0;
  long long count = 0;
  if (counts_size*COUNT_INCR < n) { // if we need a lot more counts
    count = counts[counts_size];
    tracker = counts_size;
  } else { // if we only need up to COUNT_INCR-1 counts
    tracker = n/COUNT_INCR;
    count = counts[tracker];
  }
  // cout << "\nstarting: count=" << count << endl; // TODO delete

  for(size_t i = tracker*COUNT_INCR; i <= n; ++i) {
    if (i == 0) { continue; }
    //if (digit_prod(i) % digit_sum(i) == 0) { ++count; }
    // cout << "summing " << i << ":\n"; // TODO delete
    long long dprod = digit_prod(i);
    long long dsum = digit_sum(i);
    if (dprod % dsum == 0) { ++count; }
    // cout << ((dprod % dsum == 0) ? "t" : "f") << endl; // TODO delete
    if (i % COUNT_INCR == 0) { counts[++counts_size] = count; }
  }
  // cout << "ending: count=" << count << endl; // TODO delete
  return count;
}

long long interesting_integers(long long n, long long m) {
  return count_interesting_integers(m) - count_interesting_integers(n-1);
}

int main() {
  int t;
  long long n, m;
  cin >> t; // read t. cin knows that t is an int, so it reads it as such.
  // fill sums and prods
  counts[0] = 0;
  for (size_t i = 0; i < 10; ++i) {
    sums[i] = i;
    prods[i] = i;
  }
  for (size_t i = 10; i < MEM_SIZE; ++i) {
    sums[i] = sums[i/10] + i%10;
    prods[i] = prods[i/10]*(i%10);
  }
  counts_size = 0;
  for (int i = 1; i <= t; ++i) {
    cin >> n >> m;
    cout << "Case #" << i << ": " << interesting_integers(n, m) << endl;
  }
  return 0;
}