#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#define N_MAX 1000

using namespace std;
using Integer = long long;
using Float = double;
using Table = vector<vector<Float>>;

Table table = Table(N_MAX + 1, vector<Float>(N_MAX + 1, -1));
Float f (Integer n, Integer r) {
  if (table[n][r] != -1) return table[n][r];
  if (r == 0 || n == r)  return table[n][r] = 1 / pow(2, n);
  if (0 <= r <= n)       return table[n][r] = (f(n - 1, r - 1) + f(n - 1, r)) / 2;
  throw "Invalid arguments";
}

int main () {
  Integer N, D, X_, Y_;
  cin >> N >> D >> X_ >> Y_;

  Integer const X = abs(X_);
  Integer const Y = abs(Y_);
  Integer const k = X / D;
  Integer const l = Y / D;
  Float sum = 0;

  if (
       !(X % D == 0 && Y % D == 0)
    || !(N >= k + l)
    || !((N - (k + l)) % 2 == 0)
  ) {
    printf("0\n");
    return 0;
  }

  for (Integer t = 0; t <= (N - (k + l)) / 2; t++) {
    Integer const A = k + 2 * t;
    Integer const B = N - A;
    Integer const A_plus = (A + k) / 2;
    Integer const B_plus = (B + l) / 2;

    sum += f(N, A) * f(A, A_plus) * f(B, B_plus);
  }

  printf("%.16f\n", sum);
}
