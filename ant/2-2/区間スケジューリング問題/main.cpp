#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

int N;
vector<ll> s;
vector<ll> t;

void solve () {
  vector<pair<ll, ll>> v;

  REP(i, 0, N) {
    v.push_back(make_pair(t[i], s[i]));
  }

  sort(v.begin(), v.end());

  int cnt = 0;
  ll T = 0;

  REP(i, 0, N) {
    if (v[i].second <= T) continue;

    T = v[i].first;
    cnt++;
  }

  cout << cnt << endl;
}

/**
 * main
 */
int main () {
  cin >> N;

  REP(i, 0, N) {
    ll input; cin >> input;
    s.push_back(input);
  }
  REP(i, 0, N) {
    ll input; cin >> input;
    t.push_back(input);
  }

  solve();
}
