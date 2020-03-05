#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  // begin from the state that X and Y are satisfied with A and B pizza.
  int min_price = A * X + B * Y;

  // replace A and B with AB pizza and re-calculate the price.
  for (int i = max(X, Y); i >= 0; i--) {
    int price = A * max(0, X - i) + B * max(0, Y - i) + C * 2 * i;

    if (min_price > price) {
      min_price = price;
    }
  }

  cout << min_price << '\n';
}
