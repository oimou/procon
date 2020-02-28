#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  string s;
  cin >> s;

  auto is_numeral = [](char c) {
    return ('0' <= c && c <= '9');
  };

  if ( !( is_numeral(s.at(0)) && is_numeral(s.at(1)) && is_numeral(s.at(2)) ) ) {
    printf("error\n");
  } else {
    printf("%d\n", stoi(s) * 2);
  }
}
