#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll N;
  cin >> N;
  cout << (ll)pow(floor(sqrt(N)), 2) << '\n';
}
