#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

struct ResidueClass;
ResidueClass fast_pow (ResidueClass, Integer);
Integer positive_mod (Integer, Integer);

Integer M = 1e9 + 7;
struct ResidueClass {
  Integer value;

  ResidueClass (Integer x) {
    value = x % M;
  }

  ResidueClass operator + (ResidueClass const x) const {
    return ResidueClass { positive_mod(value + positive_mod(x.value, M), M) };
  }

  ResidueClass operator - (ResidueClass const x) const {
    return ResidueClass { positive_mod(value - positive_mod(x.value, M), M) };
  }

  ResidueClass operator * (ResidueClass const x) const {
    return ResidueClass { positive_mod(value * positive_mod(x.value, M), M) };
  }

  ResidueClass inverse_element () const {
    return fast_pow(value, M - 2);
  }
};

ResidueClass fast_pow (ResidueClass x, Integer n) {
  if (n == 0) return ResidueClass(1);
  if (n % 2 == 0) return fast_pow(x * x, n / 2);
  else return x * fast_pow(x, n - 1);
}

Integer positive_mod (Integer a, Integer b) {
  Integer res = a % b;
  if (res < 0) res += b;
  return res;
}

int main () {
  Integer A_, B_, C_;
  cin >> A_ >> B_ >> C_;

  ResidueClass A(A_);
  ResidueClass B(B_);
  ResidueClass C(C_);
  ResidueClass s(B * C - A * C);
  ResidueClass t(B * C - A * B);
  ResidueClass u(A * B + A * C - B * C);
  ResidueClass u_ = u.inverse_element();
  ResidueClass r = s * u_;
  ResidueClass c = t * u_;

  printf("%d %d\n", r.value, c.value);
}
