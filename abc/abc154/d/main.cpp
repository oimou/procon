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

  deque<ll> q;
  ll sum = 0;
  ll max_sum = 0;

  REP(i, 0, N) {
    ll p; cin >> p;
    q.push_front(p);

    if (q.size() < size_t(K)) continue;
    if (q.size() == size_t(K)) {
      for (ll x : q) sum += x;
    } else {
      ll latest = q.front();
      ll oldest = q.back(); q.pop_back();
      sum -= oldest;
      sum += latest;
    }

    if (sum > max_sum) max_sum = sum;
  }

  printf("%f\n", double(max_sum + K) / 2);
}
