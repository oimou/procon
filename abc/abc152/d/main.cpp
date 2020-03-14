#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll N; cin >> N;
  ll d = ll(ceil(log10(N)));

  map<pair<int, int>, ll> table;

  REP(head, 1, 10) {
    REP(tail, 1, 10) {
      ll cnt = 0;

      // 1ケタのとき
      if (head == tail && head <= N) cnt++;

      // 2ケタ以上のとき
      REP(m, 1, d) {
        ll body_max = ll(pow(10, m - 1)) - 1;
        ll A_max = head * ll(pow(10, m)) + tail + body_max * 10;
        ll A_min = head * ll(pow(10, m)) + tail;

        if (A_min > N) break;

        if (A_max > N) {
          body_max = (N - head * ll(pow(10, m)) - tail) / 10;
        }

        cnt += body_max + 1;
      }

      table.emplace(make_pair(head, tail), cnt);

#ifdef DEBUG
      printf("%d ... %d: %lld\n", head, tail, cnt);
#endif
    }
  }

  ll cnt = 0;

  REP(head, 1, 10) {
    REP(tail, 1, 10) {
      ll n_ht = table.at(make_pair(head, tail));
      ll n_th = table.at(make_pair(tail, head));
      cnt += n_ht * n_th;
    }
  }

  cout << cnt << endl;
}
