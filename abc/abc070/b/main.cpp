#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * main
 */
int main () {
  int A, B, C, D;
  scanf("%d %d %d %d", &A, &B, &C, &D);
  int left = max(A, C);
  int right = min(B, D);
  printf("%d\n", (left < right) ? right - left : 0);
}
