#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>
#include <cmath>

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

/**
 * Legendre's theorem
 * Count the number of p in prime factors of N!
 */
int legendre (int N, int p) {
  int res = 0, k = 1, pk = p;
  while (pk <= N) {
    res += (int) N / pk;
    pk *= p;
  }
  return res;
}

/**
 * main
 */
int main () {
  constexpr auto sieve = Sieve<100>();

  int N;
  scanf("%d", &N);

  int d[7] = {0, 0, 0, 0, 0, 0, 0};
  for (int p = 2; p <= N; p++) {
    if (!sieve.is_prime[p]) continue;

    int pe = legendre(N, p);

    if (pe >= 24) d[0]++;
    if (2 <= pe && pe < 24) d[1]++;
    if (pe >= 14) d[2]++;
    if (4 <= pe && pe < 14) d[3]++;
    if (pe >= 4) d[4]++;
    if (2 <= pe && pe < 4) d[5]++;
    if (pe >= 74) d[6]++;
  }

  int ans = d[0] * (d[0] - 1) + d[1] * d[0]
    + d[2] * (d[2] - 1) + d[3] * d[2]
    + d[4] * (d[4] - 1) * (d[4] - 2) / 2 + d[5] * d[4] * (d[4] - 1) / 2
    + d[6];

  printf("%d\n", ans);

  return 0;
}
