#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  string S; cin >> S;
  int N = S.length();

  string S1 = S.substr(0, (N - 1) / 2);
  string S2 = S.substr((N + 3) / 2 - 1);

  string R(S); reverse(R.begin(), R.end());
  string R1(S1); reverse(R1.begin(), R1.end());
  string R2(S2); reverse(R2.begin(), R2.end());

  if (S == R && S1 == R1 && S2 == R2) cout << "Yes" << endl;
  else cout << "No" << endl;
}
