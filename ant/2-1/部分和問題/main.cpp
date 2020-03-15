#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const ll MAX_N = 1e8;

ll n;
vector<ll> a;
ll k;

bool dfs (int i, ll sum) {
  if (i == n) return sum == k;
  if (dfs(i + 1, sum + a[i])) return true;
  if (dfs(i + 1, sum)) return true;
  return false;
}

void solve () {
  if (dfs(0, 0)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

/**
 * main
 */
int main () {
  cin >> n;

  REP(i, 0, n) {
    ll input; cin >> input;
    a.push_back(input);
  }

  cin >> k;

  solve();
}
