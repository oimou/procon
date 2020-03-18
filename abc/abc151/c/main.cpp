#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const int MAX_N = 1e5;
static const int MAX_M = 1e5;

bool accepted[MAX_N + 1];
int penalty[MAX_M + 1];

/**
 * main
 */
int main () {
  int N; cin >> N;
  int M; cin >> M;

  REP(i, 0, M) {
    int p; cin >> p;
    string S; cin >> S;

    if (S == "AC") accepted[p] = true;
    if (S == "WA" && !accepted[p]) penalty[p]++;
  }

  int sum_a = 0;
  int sum_p = 0;

  for (int p = 1; p <= N; p++) {
    sum_a += (int) accepted[p];
    sum_p += (accepted[p]) ? penalty[p] : 0;
  }

  printf("%d %d\n", sum_a, sum_p);
}
