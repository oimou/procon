#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

Integer min_i (Integer W, Integer H) {
  return min(W, H);
}

Integer min_t (Integer W, Integer H) {
  Integer res = 1e10;

  for (Integer l = H / 2; l < H; l++) {
    Integer S_head = W * (H - l);
    Integer S_larger  = (Integer) (l *  ceil((double)W / 2));
    Integer S_smaller = (Integer) (l * floor((double)W / 2));
    Integer S_max = max(S_head, S_larger);
    Integer S_min = min(S_head, S_smaller);
    Integer dS = S_max - S_min;

    if (dS < res) res = dS;
    if (S_head < S_smaller) break;
  }

  return res;
}

int main () {
  Integer H, W;
  cin >> H >> W;

  int ans = (H % 3 == 0 || W % 3 == 0)
    ? 0
    : min(min_i(W, H), min(min_t(W, H), min_t(H, W)));

  cout << ans << "\n";
}
