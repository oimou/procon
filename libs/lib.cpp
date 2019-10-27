#include <bits/stdc++.h>

using namespace std;

template <typename T>
void swap (T * a, T * b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

template <typename T>
void print_array (T arr[], size_t n) {
  for (int i = 0; i < n; i++) printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
}

void sieve (bool is_prime[], Integer N) {
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
