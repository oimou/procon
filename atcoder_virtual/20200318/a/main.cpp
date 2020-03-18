#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

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

/**
 * main
 */
int main () {
  Sieve<10000> sieve;
  int cnt = 0;
  int n; cin >> n;

  for (int i = 2; i < n; i++) {
    if (sieve.is_prime[i]) cnt++;
  }

  cout << cnt << endl;
}
