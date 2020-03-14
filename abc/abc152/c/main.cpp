#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  int N; cin >> N;

  ll cnt = 0;
  ll min_p = 2 * 1e5 + 1;
  REP(i, 0, N) {
    ll p; cin >> p;

    if (p <= min_p) {
      cnt++;
      min_p = p;
    }
  }

  cout << cnt << endl;
}
