#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  int N; cin >> N;
  int M; cin >> M;

  cout << (N * (N - 1) / 2 + M * (M - 1) / 2) << endl;
}
