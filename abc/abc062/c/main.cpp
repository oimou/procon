#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

Integer min_i (Integer H, Integer W) {
  return min(H, W);
}

Integer min_t (double H, double W) {
  Integer h1 =  ceil( W * H / ( W + floor(W / 2) ) );
  Integer h2 = floor( W * H / ( W +  ceil(W / 2) ) );
  return min(
    h1 * ceil(W / 2) - W * (H - h1),
    W * (H - h2) - h2 * floor(W / 2)
  );
}

int main () {
  Integer H, W;
  cin >> H >> W;

  Integer ans = (H % 3 == 0 || W % 3 == 0)
    ? 0
    : min(min_i(H, W), min(min_t(H, W), min_t(W, H)));

  cout << ans << "\n";
}
