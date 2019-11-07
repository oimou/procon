#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>

using namespace std;

/**
 * main
 */
int main () {
  int a, b, h;
  scanf("%d %d %d", &a, &b, &h);
  printf("%d\n", (a + b) * h / 2);
}
