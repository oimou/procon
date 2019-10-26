#include <bits/stdc++.h>

using namespace std;

vector<int> get_divisors (int n) {
  vector<int> v;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      int I = n / i;

      v.push_back(i);
      if (i != I) v.push_back(I);
    }
  }
  return v;
}

int gcd (int a, int b) {
  return (b == 0) ? a : gcd(b, a % b);
}

int main () {
  int A, B, K;
  cin >> A >> B >> K;

  vector<int> cd = get_divisors(gcd(A, B));

  sort(cd.begin(), cd.end(), greater<int>());

  cout << cd.at(K - 1) << "\n";
}
