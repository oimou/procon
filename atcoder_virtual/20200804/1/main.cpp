#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * Sieve of Eratosthenes
 */
template <size_t N>
struct Sieve {
  using Integer = int;
  bool is_prime[N + 1];
  constexpr Sieve() : is_prime() {
    Integer sqrt_N = sqrt(N);

    for (Integer i = 0; i <= N; i++) is_prime[i] = true;

    is_prime[1] = false;
    is_prime[2] = true;

    for (Integer p = 2; p <= sqrt_N; p++) {
      if (is_prime[p] == false) continue;

      is_prime[p] = true;

      for (Integer i = p + 1; i <= N; i++) {
        if (i % p == 0) is_prime[i] = false;
      }
    }
  }
};

Sieve<200> sieve;

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
    if (m % i == 0 && sieve.is_prime[i]) {
      divisors *= (count_factors(m, i) + 1);
    }
  }
  return divisors;
}

/**
 * main
 */
int main () {
  int N, count = 0;
  cin >> N;

  for (int m = 1; m <= N; m++) {
    if (m % 2 != 1) continue;
    if (factorize_and_count(m) == 8) count++;
  }

  cout << count << '\n';
}
