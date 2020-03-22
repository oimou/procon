#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  int L; cin >> L;

  double ans = pow((double) L / 3.0, 3);

  printf("%f\n", ans);
}
