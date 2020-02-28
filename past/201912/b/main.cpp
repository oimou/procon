#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  int N;
  scanf("%d", &N);

  int prev;
  scanf("%d", &prev);
  N--;

  while (N--) {
    int curr;
    scanf("%d", &curr);

    if (curr == prev) printf("stay\n");
    else if (curr > prev) printf("up %d\n", curr - prev);
    else if (curr < prev) printf("down %d\n", prev - curr);

    prev = curr;
  }
}
