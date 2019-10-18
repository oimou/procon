#include <iostream>
#include <string>
#include <boost/math/common_factor_rt.hpp>

using namespace std;
using Integer = long long;

int main () {
  Integer N, M;
  string S, T;

  cin >> N >> M >> S >> T;

  Integer l = boost::math::lcm(N, M);
  Integer g = boost::math::gcd(N, M);
  Integer N_ = N / g;
  Integer M_ = M / g;

  for (Integer d = 0; d < g; d++) {
    if (S.at(N_ * d) != T.at(M_ * d)) {
      cout << -1 << "\n";
      return 0;
    }
  }

  cout << l << "\n";
}
