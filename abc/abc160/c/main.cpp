#include <bits/stdc++.h>
#define REP(i, a, b) for (ll i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll K; cin >> K;
  ll N; cin >> N;

  vector<ll> A(N);

  REP(i, 0, N) cin >> A[i];

  // sort(A.begin(), A.end());

  ll min_d = K;

  REP(i, 0, N) {
    ll from = i;
    ll to = (i - 1 + N) % N;
    ll d = (A.at(to) - A.at(from) + K) % K;

    if (d < min_d) min_d = d;
  }

  cout << min_d << endl;
}
