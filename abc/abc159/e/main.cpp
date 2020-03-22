#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const int H_MAX = 10;
static const int W_MAX = 1000;

/**
 * main
 */
int main () {
  int H; cin >> H;
  int W; cin >> W;
  int K; cin >> K;

  int table[H_MAX][W_MAX];

  REP(i, 0, H) {
    string line; cin >> line;

    REP(j, 0, W) {
      table[i][j] = (line[j] == '1') ? 1 : 0;
    }
  }

#ifdef DEBUG
  int sum;

  sum = 0;
  REP(i, 0, H) {

    REP(j, 0, W) {
      sum += table[i][j];
    }

    printf("%d\n", sum);
  }

  printf("\t");
  sum = 0;
  REP(j, 0, W) {

    REP(i, 0, H) {
      sum += table[i][j];
    }

    printf("%d ", sum);
  }
  printf("\n");
#endif
}
