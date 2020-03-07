#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  long long N, A, B;
  scanf("%lld %lld %lld", &N, &A, &B);

  if (A + B == 0) {
    printf("0\n");
  } else {
    long long q = N / (A + B);
    long long r = N % (A + B);

    printf("%lld\n", q * A + min(A, r));
  }
}
