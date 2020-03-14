#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  int N; cin >> N;
  int K; cin >> K;

  vector<ll> h(N);

  REP(i, 0, N) cin >> h[i];

  sort(h.begin(), h.end(), greater<ll>());

  ll sum = 0;

  REP(i, 0, N) {
    if (i < K) continue;

    sum += h[i];
  }

  cout << sum << endl;
}
