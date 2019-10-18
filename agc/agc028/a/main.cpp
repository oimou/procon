#include <iostream>
#include <string>
#include <boost/math/common_factor_rt.hpp>

using namespace std;

int main () {
  int N, M;
  string S, T;

  cin >> N >> M >> S >> T;

  int l = boost::math::lcm(N, M);
  int g = boost::math::gcd(N, M);
  int N_ = N / g;
  int M_ = M / g;

  for (int d = 0; d < g; d++) {
    if (S.at(N_ * d) != T.at(M_ * d)) {
      cout << -1 << "\n";
      return 0;
    }
  }

  cout << l << "\n";
}
