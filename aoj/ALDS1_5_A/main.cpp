#include <bits/stdc++.h>

using namespace std;

bool dp[21][2001];
bool solve (vector<int> & v, size_t idx, int m) {
  // already calculated?
  if (dp[idx][m]) {
    return dp[idx][m];
  }

  // not calculated yet?
  if (m == 0) {
    dp[idx][m] = true;
  } else if (idx == v.size()) {
    dp[idx][m] = false;
  } else if (solve(v, idx + 1, m)) {
    dp[idx][m] = true;
  } else if (solve(v, idx + 1, m - v[idx])) {
    dp[idx][m] = true;
  } else {
    dp[idx][m] = false;
  }

  return dp[idx][m];
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
