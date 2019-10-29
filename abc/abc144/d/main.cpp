#include <bits/stdc++.h>

using namespace std;

int main () {
  double a, b, x;
  cin >> a >> b >> x;

  double V0 = a * a * b;
  double theta;

  if (x >= V0 / 2)
    theta = atan(2 * (a * a * b - x) / (a * a * a));
  else
    theta = atan(a * b * b / (2 * x));

  cout << setprecision(16) << theta * 180 / M_PI << "\n";
}
