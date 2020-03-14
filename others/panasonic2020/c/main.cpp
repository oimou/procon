#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll a; cin >> a;
  ll b; cin >> b;
  ll c; cin >> c;

  ll lh = 4 * a * b;
  ll rh = a * a + b * b + c * c + 2 * (a * b - b * c - c * a);

  if (c- a - b <= 0) {
    cout << "No" << endl;
  } else {
    cout << (lh < rh ? "Yes" : "No") << endl;
  }
}
