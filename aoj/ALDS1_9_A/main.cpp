#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  int H; cin >> H;
  vector<ll> A(H + 1);

  for (int i = 1; i <= H; i++) cin >> A[i];

  REP(i, 0, H) {
    int id = i + 1;
    ll k = A[id];
    int p_id = id / 2;
    int l_id = id * 2;
    int r_id = id * 2 + 1;

    printf("node %d: key = %lld, ", id, k);

    if (p_id > 0) printf("parent key = %lld, ", A[p_id]);
    if (l_id <= H) printf("left key = %lld, ", A[l_id]);
    if (r_id <= H) printf("right key = %lld, ", A[r_id]);

    printf("\n");
  }
}
