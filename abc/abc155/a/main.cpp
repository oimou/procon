#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll A, B, C;
  cin >> A >> B >> C;
  if (A == B && B == C && C == A) {
    cout << "No\n";
  } else if (A == B || B == C || C == A) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
