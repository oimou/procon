#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  int N, M;
  cin >> N >> M;

  int d[4] = {-1, -1, -1, -1};
  bool invalid = false;

  while (M--) {
    int s, c;
    cin >> s >> c;

    for (int i = 1; i <= 3; i++) {
      if (s == i) {
        if (d[s] == -1) {
          d[s] = c;
        } else if (d[s] != c) {
          invalid = true;
          break;
        }
      }
    }
  }

  if (!invalid) {
    if (N == 1) {
      printf("%d\n", (d[1] == -1 ? 0 : d[1]));
    }
    if (N == 2) {
      if (d[1] == 0) invalid = true;
      else printf("%d%d\n", (d[1] == -1 ? 1 : d[1]), (d[2] == -1 ? 0 : d[2]));
    }
    if (N == 3) {
      if (d[1] == 0) invalid = true;
      else printf("%d%d%d\n", (d[1] == -1 ? 1 : d[1]), (d[2] == -1 ? 0 : d[2]), (d[3] == -1 ? 0 : d[3]));
    }
  }

  if (invalid) cout << "-1\n";
}
