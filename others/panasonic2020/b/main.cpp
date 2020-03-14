#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll H; cin >> H;
  ll W; cin >> W;

  if (H == 1 || W == 1) {
    cout << 1 << endl;
  } else {
    ll RH = H % 2;
    ll RW = W % 2;
    ll ans = (H / 2) * (W / 2) * 2
      + (W / 2) * RH
      + (H / 2) * RW
      + RH * RW;

    cout << ans << endl;
  }
}
