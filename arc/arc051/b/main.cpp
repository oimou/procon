#include <iostream>

using namespace std;
using Integer = long long;

Integer F (Integer n) {
  Integer a = 0;
  Integer b = 1;
  Integer c = 1;
  for (Integer i = 0; i < n - 1; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main () {
  Integer K;
  cin >> K;
  cout << F(K + 2) << " " << F(K + 1) << "\n";
}
