#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>

using namespace std;

/**
 * main
 */
int main () {
  int c, a;
  scanf("%d %d", &c, &a);
  printf("%d\n", c * a / 2);
}
