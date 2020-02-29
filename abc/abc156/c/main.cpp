#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  int N;
  cin >> N;

  int A = 0;
  int B = 0;
  int input;
  while (cin >> input) {
    A += input;
    B += input * input;
  }

  auto f = [&](int p) {
    return N * p * p - 2 * A * p + B;
  };

  int ans = min(f(floor((double) A / N)), f(ceil((double) A / N)));

  cout << ans << '\n';
}
