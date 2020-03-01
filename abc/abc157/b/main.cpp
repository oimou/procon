#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  using Cell = pair<int, bool>;

  vector<Cell> t;

  for (int i = 0; i < 9; i++) {
    int input;
    cin >> input;
    t.push_back(make_pair(input, false));
  }

  int N;
  cin >> N;

  while (N--) {
    int input;
    cin >> input;

    for (int i = 0; i < 9; i++) {
      if (t.at(i).first == input) t.at(i).second = true;
    }
  }

  auto f = [&](int a, int b, int c) {
    return (t.at(a).second && t.at(b).second && t.at(c).second);
  };

  if (f(0, 3, 6) || f(1, 4, 7) || f(2, 5, 8) || f(0, 1, 2) || f(3, 4, 5) || f(6, 7, 8) || f(0, 4, 8) || f(2, 4, 6)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
