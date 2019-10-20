#include <iostream>
#include <cmath>

using namespace std;
using Integer = long long;

int main () {
  Integer N, T;
  cin >> N >> T;

  Integer prev, curr, sum = 0;
  for (Integer i = 0; i < N; i++) {
    cin >> curr;
    if (i > 0) sum += max(curr - prev - T, (Integer) 0);
    prev = curr;
  }

  cout << curr + T - sum << "\n";
}
