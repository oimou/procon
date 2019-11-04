#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>

using namespace std;

/**
 * main
 */
int main () {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  printf("%d\n", (b - a - 1) * (b - a) / 2 - a);
}
