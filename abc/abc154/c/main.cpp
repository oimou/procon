#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  int N; cin >> N;
  vector<ll> a(N);

  REP(i, 0, N) cin >> a[i];

  sort(a.begin(), a.end());

  ll prev = 0;
  REP(i, 0, N) {
    if (prev == a[i]) {
      cout << "NO" << endl;
      return 0;
    }
    prev = a[i];
  }

  cout << "YES" << endl;
  return 0;
}
