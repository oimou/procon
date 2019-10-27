#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

bool is_prime (Integer n) {
  if (n == 1) return false;
  if (n == 2) return true;

  long sqrtn = ceil(sqrt(n));

  for (Integer i = 2; i <= sqrtn; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

int main () {
  Integer N;
  cin >> N;

  if (N == 1) {
    cout << "Not Prime\n";
  } else if (N % 2 != 0 && N % 3 != 0 && N % 5 != 0) {
    cout << "Prime\n";
  } else {
    cout << (is_prime(N) ? "Prime" : "Not Prime") << "\n";
  }
}
