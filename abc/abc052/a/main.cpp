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
  printf("%d\n", max(A*B, C*D));
}
