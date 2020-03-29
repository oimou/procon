#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll X; cin >> X;

  ll n500 = X / 500;
  ll n5 = (X % 500) / 5;

  cout << (n500 * 1000 + n5 * 5) << endl;
}
