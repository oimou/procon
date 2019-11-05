#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>

using namespace std;

/**
 * main
 */
int main () {
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);
  printf("%d\n", 2 * (A*B + B*C + C*A));
}
