#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

bool isACGT (char c) {
  return (c == 'A' || c == 'C' || c == 'G' || c == 'T');
}

/**
 * main
 */
int main () {
  string S;
  cin >> S;

  int count = 0;
  int max_count = 0;
  for (char c : S) {
    if (isACGT(c)) {
      count++;
    } else  {
      max_count = max(max_count, count);
      count = 0;
    }
  }
  max_count = max(max_count, count);

  cout << max_count << '\n';
}
