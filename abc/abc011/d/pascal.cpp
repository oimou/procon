#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using Integer = long long;
using Float = double;
using Table = vector<vector<Float>>;

Table table = Table(1001, vector<Float>(1001, -1.0));
Integer s = 2;
Float f (Integer n, Integer r) {
  if (table[n][r] != -1.0) return table[n][r];
  if (r == 0 || n == r)
    return table[n][r] = 1 / pow(s, n);
  if (0 <= r <= n)
    return table[n][r] = (f(n - 1, r - 1) + f(n - 1, r)) / s;
  throw "invalid arguments";
}

int main () {
  for (Integer n = 0; n <= 1000; n++) {
    for (Integer r = 0; r <= n; r++) {
      if (n == 1000)
      cout << "f(" << n << ", " << r << ") = " << f(n, r) << "\n";
    }
  }
}
