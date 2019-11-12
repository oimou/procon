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

  int a_min = 1001;
  int a_max = -1;
  while (N--) {
    int x;
    scanf("%d", &x);
    if (x < a_min) a_min = x;
    if (x > a_max) a_max = x;
  }

  printf("%d\n", a_max - a_min);
}
