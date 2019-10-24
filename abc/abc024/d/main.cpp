#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

int main () {
  Integer A, B, C;
  cin >> A >> B >> C;

  if (A <= 1) {
    printf("%d %d\n", B - 1, C - 1);
  } else {
    double b = (double) B / A;
    double g = (double) C / A;
    Integer r = round((b - 1) * g / (1 - (b - 1) * (g - 1)));
    Integer c = round((g - 1) * b / (1 - (b - 1) * (g - 1)));
    printf(
      "%f %f %f %f\n",
      b,
      g,
      (b - 1.0) * g / (1.0 - (b - 1.0) * (g - 1.0)),
      (g - 1.0) * b / (1.0 - (b - 1.0) * (g - 1.0))
    );
    printf("%d %d\n", r, c);
  }
}
