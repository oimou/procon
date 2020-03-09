#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll N, Q;
  string S;

  cin >> N >> S >> Q;

  set<ll> M[26];

  REP(i, 0, N) {
    char c = S[i];
    ll c_i = c - 'a';
    M[c_i].insert(i);
  }

  REP(j, 0, Q) {
    ll type;
    scanf("%lld", &type);

    if (type == 1) {
      ll i;
      char c;

      scanf("%lld %c", &i, &c);

      if (S[i - 1] == c) continue;

      M[S[i - 1] - 'a'].erase(i - 1);
      M[c - 'a'].insert(i - 1);
      S[i - 1] = c;
    } else {
      ll l, r;
      scanf("%lld %lld", &l, &r);
      ll cnt = 0;

      REP(c, 0, 26) {
        auto it = M[c].lower_bound(l - 1);
        if (it == M[c].end()) continue;
        if (*it <= r - 1) cnt++;
      }

      printf("%lld\n", cnt);
    }
  }
}
