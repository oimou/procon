#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

namespace mp = boost::multiprecision;

using namespace std;
using Integer = unsigned long long;
using MPInteger = mp::cpp_int;
using MPFloat = mp::cpp_bin_float_quad;

MPInteger factorial (Integer n) {
  MPInteger res = 1;
  for (Integer i = 1; i <= n; ++i)
    res *= i;
  return res;
}

int main () {
  Integer N, D;
  long long X_, Y_;
  cin >> N >> D >> X_ >> Y_;

  Integer const X = abs(X_);
  Integer const Y = abs(Y_);

  if (!(X % D == 0 && Y % D == 0)) {
    cout << 0 << endl;
    return 0;
  }

  Integer const k = X / D;
  Integer const l = Y / D;

  if (!(N >= k + l) || !((N - (k + l)) % 2 == 0)) {
    cout << 0 << endl;
    return 0;
  }

  Integer const k_max = (N - (k + l)) / 2;
  MPInteger const N_ = factorial(N);
  MPInteger sum = 0;

  for (Integer k_ = 0; k_ <= k_max; k_++) {
    Integer const l_ = (N - k - 2 * k_ - l) / 2;
    MPInteger const a_ = factorial(k + k_);
    MPInteger const b_ = factorial(k_);
    MPInteger const c_ = factorial(l + l_);
    MPInteger const d_ = factorial(l_);
    sum += N_ / (a_ * b_ * c_ * d_);
  }

  MPInteger const four_N = mp::pow(MPInteger(4), N);
  MPFloat const answer = MPFloat(sum) / MPFloat(four_N);

  cout << setprecision(16) << answer << endl;
}
