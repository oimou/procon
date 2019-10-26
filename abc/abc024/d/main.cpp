#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

struct ResidueClass;
ResidueClass fast_pow (ResidueClass, Integer);
Integer positive_mod (Integer, Integer);

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

  ResidueClass A(A_), B(B_), C(C_);
  ResidueClass s(B * C - A * C);
  ResidueClass t(B * C - A * B);
  ResidueClass u(A * B + A * C - B * C);
  ResidueClass r = s / u;
  ResidueClass c = t / u;

  printf("%d %d\n", r.value, c.value);
}
