#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

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

/**
 *  剰余類
 */
struct ResidueClass {
  Integer value;
  Integer M = 1e9 + 7;

  ResidueClass (Integer x) {
    value = positive_mod(x, M);
  }

  ResidueClass operator + (ResidueClass const x) const {
    return ResidueClass { positive_mod(value + x.value, M) };
  }

  ResidueClass operator - (ResidueClass const x) const {
    return ResidueClass { positive_mod(value - x.value, M) };
  }

  ResidueClass operator * (ResidueClass const x) const {
    return ResidueClass { positive_mod(value * x.value, M) };
  }

  ResidueClass operator / (ResidueClass const x) const {
    ResidueClass x_inv = fast_pow(x, M - 2);
    return ResidueClass { positive_mod(value * x_inv.value, M) };
  }

  static ResidueClass factorial (ResidueClass n) {
    ResidueClass res(1);
    for (int i = n.value; i >= 1; i--) res = res * ResidueClass(i);
    return res;
  }

  static ResidueClass fast_pow (ResidueClass x, Integer n) {
    if (n == 0) return ResidueClass(1);
    if (n % 2 == 0) return fast_pow(x * x, n / 2);
    else return x * fast_pow(x, n - 1);
  }

  static Integer positive_mod (Integer a, Integer b) {
    Integer res = a % b;
    if (res < 0) res += b;
    return res;
  }
};
