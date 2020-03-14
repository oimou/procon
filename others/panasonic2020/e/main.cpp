#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const int M = 2000;

vector<bool> ab(100000, false);
vector<bool> ac(100000, false);
vector<bool> bc(100000, false);

bool match (char x, char y) {
  return (x == '?' || y == '?' || x == y);
}

/**
 * main
 */
int main () {
  string a; cin >> a;
  string b; cin >> b;
  string c; cin >> c;

  int la = int(a.length());
  int lb = int(b.length());
  int lc = int(c.length());

  REP(i, 0, la)
    REP(j, 0,lb)
      if (!match(a[i], b[j]))
        ab[i - j + 50000] = true;

  REP(i, 0, la)
    REP(j, 0,lc)
      if (!match(a[i], c[j]))
        ac[i - j + 50000] = true;

  REP(i, 0, lb)
    REP(j, 0,lc)
      if (!match(b[i], c[j]))
        bc[i - j + 50000] = true;

  int ans = 3 * M;

  for (int i = -2 * M; i <= 2 * M; i++) {
    for (int j = -2 * M; j <= 2 * M; j++) {
      if (!(ab[i + 50000] || ac[j + 50000] || bc[j - i + 50000])) {
        int L = min(0, min(i, j));
        int R = max(la, max(lb + i, lc + j));

        ans = min(ans, R - L);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
