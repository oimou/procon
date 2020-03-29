#include <bits/stdc++.h>
#define REP(i, a, b) for (ll i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll X; cin >> X;
  ll Y; cin >> Y;
  ll A; cin >> A;
  ll B; cin >> B;
  ll C; cin >> C;

  priority_queue<ll> P;
  priority_queue<ll> Q;
  priority_queue<ll> R;

  REP(i, 0, A) {
    ll input; cin >> input;
    P.push(input);
  }

  REP(i, 0, B) {
    ll input; cin >> input;
    Q.push(input);
  }

  REP(i, 0, C) {
    ll input; cin >> input;
    R.push(input);
  }

  vector<ll> v;

  REP(i, 0, X) {
    v.push_back(P.top()); P.pop();
  }

  REP(i, 0, Y) {
    v.push_back(Q.top()); Q.pop();
  }

  while (!R.empty()) {
    v.push_back(R.top()); R.pop();
  }

  sort(v.begin(), v.end(), greater<ll>());

  ll ans = 0;

  REP(i, 0, X + Y) ans += v.at(i);

  cout << ans << endl;
}
