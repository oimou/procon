#include <bits/stdc++.h>
#define REP(i, a, b) for (ll i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const ll MAX_N = 2 * 1e3;
static const ll INFTY = 2 * 1e3;
static const ll WHITE = 0;
static const ll GRAY = 1;
static const ll BLACK = 2;

ll N, X, Y;
vector<pair<ll, ll>> adj[MAX_N];
vector<ll> ans(MAX_N + 1, 0);

void dijkstra (ll from) {
  priority_queue<pair<ll, ll>> PQ;
  ll color[MAX_N];
  ll d[MAX_N];

  REP(i, 0, N) {
    d[i] = INFTY;
    color[i] = WHITE;
  }

  d[from] = 0;
  PQ.push(make_pair(0, from));
  color[from] = GRAY;

  while (!PQ.empty()) {
    pair<ll, ll> f = PQ.top(); PQ.pop();
    ll u = f.second;

    color[u] = BLACK;

    if (d[u] < f.first * (-1)) continue;

    for (ll j = 0; j < (ll)adj[u].size(); j++) {
      ll v = adj[u][j].first;

      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        PQ.push(make_pair(d[v] * -1, v));
        color[v] = GRAY;
      }
    }
  }

  REP(i, 0, N) {
#ifdef DEBUG
    // printf("%lld -> %lld: %lld\n", from, i, d[i]);
#endif
    ans.at(d[i])++;
  }
}

/**
 * main
 */
int main () {
  cin >> N;
  cin >> X;
  cin >> Y;

  REP(i, 0, N) {
    if (i + 1 <= N - 1) adj[i].push_back(make_pair(i + 1, 1));
    if (i - 1 >= 0) adj[i].push_back(make_pair(i - 1, 1));
    if (i == X - 1) adj[i].push_back(make_pair(Y - 1, 1));
    if (i == Y - 1) adj[i].push_back(make_pair(X - 1, 1));
  }

  REP(i, 0, N) {
    dijkstra(i);
  }

  for (ll i = 1; i <= N - 1; i++) {
    cout << (ans.at(i) / 2) << endl;
  }
}
