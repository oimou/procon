#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  int A, B;
  cin >> A >> B;

  int ans = -1;
  for (size_t n = 1; n <= 1009; n++) {
    if (floor(n * 8 / 100) == A && floor(n * 10 / 100) == B) {
      ans = n;
      break;
    }
  }

  printf("%d\n", ans);
}
