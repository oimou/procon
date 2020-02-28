#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  int NTH = 6 - 3;
  int input;
  vector<int> v;

  while (cin >> input) {
    v.push_back(input);
  }

  nth_element(v.begin(), v.begin() + NTH, v.end());

  printf("%d\n", v.at(NTH));
}
