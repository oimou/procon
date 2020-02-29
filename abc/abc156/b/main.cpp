#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  long N, K;
  cin >> N >> K;

  int d = floor(log(N) / log(K)) + 1;

  cout << d << '\n';
}
