#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  string l1, l2;
  cin >> l1 >> l2;

  reverse(l1.begin(), l1.end());

  cout << ((l1 == l2) ? "YES" : "NO") << '\n';
}
