#include <iostream>

using namespace std;
using Integer = long long;

double f (Integer n, Integer r) {
  if (n >= 0 && r == 0) return 1;
  if (n == 0 && r >= 1) return 0;
  if (n >= 1 && r >= 1) return f(n - 1, r - 1) + f(n - 1, r);
  throw "invalid arguments";
}

int main () {
  for (Integer n = 0; n < 10; n++) {
    for (Integer r = 0; r < 10; r++) {
      cout << "f(" << n << ", " << r << ") = " << f(n, r) << "\n";
    }
  }
}
