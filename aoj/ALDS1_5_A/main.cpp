#include <bits/stdc++.h>

using namespace std;

bool solve (vector<int> & v, size_t idx, int m) {
  if (m == 0) return true;
  if (idx == v.size()) return false;

  return solve(v, idx + 1, m - v[idx]) || solve(v, idx + 1, m);
}

/**
 * main
 */
int main () {
  vector<int> v;
  int n;
  cin >> n;

  while (n--) {
    int input;
    cin >> input;
    v.push_back(input);
  }

  int q;
  cin >> q;

  while (q--) {
    int input;
    cin >> input;
    cout << (solve(v, 0, input) ? "yes" : "no") << '\n';
  }
}
