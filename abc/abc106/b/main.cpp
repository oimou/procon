#include <iostream>
#include <cmath>

#define N_MAX 200

using namespace std;

bool is_combosite[N_MAX + 1];
bool is_prime (long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  if (is_combosite[n]) return false;

  long sqrtn = ceil(sqrt(n));

  for (long i = 2; i <= sqrtn; i++) {
    if (n % i == 0) {
      is_combosite[n] = true;
      return false;
    }
  }

  return true;
}

int count_factors (int n, int p) {
  int x = n;
  int count = 0;
  while (x % p == 0) {
    x /= p;
    count++;
  }
  return count;
}

int factorize_and_count (int m) {
  int divisors = 1;
  for (int i = 1; i <= m; i++) {
    if (m % i == 0 && is_prime(i)) {
      divisors *= (count_factors(m, i) + 1);
    }
  }
  return divisors;
}

int main () {
  int N, count = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0) continue;
    if (factorize_and_count(i) == 8) count++;
  }
  cout << count << "\n";
}
