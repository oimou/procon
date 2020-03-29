#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  string S; cin >> S;

  if (S.at(2) == S.at(3) && S.at(4) == S.at(5)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
