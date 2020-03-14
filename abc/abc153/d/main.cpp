#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll H; cin >> H;

  ll h = 0;
  while (H > 1) {
    H /= 2;
    h++;
  }

  ll ans = 1;
  REP(i, 0, h + 1) ans *= 2;
  ans -= 1;

  cout << ans << endl;
}
