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
  ll N;
  cin >> N;

  bool denied = false;

  while (N--) {
    ll A;
    cin >> A;

    if (A % 2 == 0 && !(A % 3 == 0 || A % 5 == 0)) {
      denied = true;
    }
  }

  cout << (denied ? "DENIED" : "APPROVED") << "\n";
}
