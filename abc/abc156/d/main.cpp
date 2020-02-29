#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

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

/**
 * main
 */
int main () {
  Integer n_, a_, b_;
  cin >> n_ >> a_ >> b_;

  ResidueClass n(n_), a(a_), b(b_);

  ResidueClass total = ResidueClass::fast_pow(ResidueClass(2), n_) - ResidueClass(1);

  ResidueClass nCa(1);
  for (size_t j_ = 1; j_ <= a_; j_++) {
    ResidueClass j(j_);
    ResidueClass den = n - j + 1;
    ResidueClass num = j;

    nCa = nCa * (den / num);
  }

  ResidueClass nCb(1);
  for (size_t j_ = 1; j_ <= b_; j_++) {
    ResidueClass j(j_);
    ResidueClass den = n - j + 1;
    ResidueClass num = j;

    nCb = nCb * (den / num);
  }

  ResidueClass ans = total - nCa - nCb;

  cout << ans.value << '\n';
}
