#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  string a; cin >> a;
  string b; cin >> b;
  string c; cin >> c;

  int la = a.size();
  int lb = b.size();
  int lc = c.size();

  REP(i, 0, la + lb + 1) {
    int p_ba = i - lb;
    int l = min(p_ba + 0,  0);
    int r = max(p_ba + lb, la);
    bool is_valid = true;

    REP(j, 0, r - l) {
    }
  }
}
