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
  string S;
  cin >> S;

  if (
       S == "hi"
    || S == "hihi"
    || S == "hihihi"
    || S == "hihihihi"
    || S == "hihihihihi"
    || S == "hihihihihihi"
    || S == "hihihihihihihi"
    || S == "hihihihihihihihi"
    || S == "hihihihihihihihihi"
    || S == "hihihihihihihihihihi"
  ) printf("Yes\n");
  else printf("No\n");
}
