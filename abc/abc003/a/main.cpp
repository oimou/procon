#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>

using namespace std;

/**
 * main
 */
int main () {
  int N;
  scanf("%d", &N);
  printf("%d\n", 5000 * (N + 1));
}
