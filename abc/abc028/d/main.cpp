#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>

using namespace std;

/**
 * main
 */
int main () {
  double N, K;
  scanf("%lf", &N);
  scanf("%lf", &K);
  double ans = ((K - 1) * (N - K) * 6 + (N - 1) * 3 + 1) / (N * N * N);
  printf("%.20lf\n", ans);
}
