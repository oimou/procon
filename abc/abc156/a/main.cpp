#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  // if (N >= 10) then I = R
  // else R = I - 100 * (10 - N)

  int N, R;
  cin >> N >> R;
  cout << ((N >= 10) ? R : (R + 100 * (10 - N))) << '\n';
}
