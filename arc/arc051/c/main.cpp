#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;
using Item = tuple<int, double, int>;

void sort (vector<Item> & a) {
  sort(a.begin(), a.end(), [&](Item const & lh, Item const & rh) {
    return (get<2>(lh) - get<2>(rh)) + (get<1>(lh) - get<1>(rh)) < 0;
  });
}

/**
 *  剰余類
 */
struct ResidueClass {
  using Integer = long long;
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

/**
 * main
 */
int main () {
  int N, A, B;
  cin >> N >> A >> B;

  vector<Item> a(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    a[i] = make_tuple(x, log(x) / log(A), 0);
  }

  sort(a);

  if (A != 1) {
    for (int i = 0; i < 1000; i++) {
      get<2>(a[0])++;
      sort(a);
      // for (auto item : a) printf("%d %d\n", get<0>(item), get<2>(item)); printf("-\n");
      for (auto item : a) printf("%d\t", get<2>(item)); printf("\n");
    }
  }

  for (auto item : a) {
    int m = get<2>(item);
    ResidueClass A_(A), a_(get<0>(item));
    printf("%d\n", (ResidueClass::fast_pow(A_, m) * a_).value);
  }
}
