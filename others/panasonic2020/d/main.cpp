#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;
using Series = vector<int>;

/**
 * main
 */
int main () {
  int N; cin >> N;

  Series s0 = {0};
  vector<Series> prev;

  prev.push_back(s0);

  REP(n, 1, N) {
    vector<Series> curr;

    for (Series & s : prev) {
      int max_d = *max_element(s.begin(), s.end());

      REP(d, 0, max_d + 2) {
        Series t(s.size());

        copy(s.begin(), s.end(), t.begin());
        t.push_back(d);
        curr.push_back(t);
      }
    }

    prev = curr;
  }

  for (Series & s : prev) {
    for (int d : s) {
      printf("%c", 'a' + d);
    }
    printf("\n");
  }
}
