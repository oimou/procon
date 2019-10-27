#include <bits/stdc++.h>

using namespace std;

int main () {
  long long N;
  cin >> N;

  if (N == 1) {
    cout << "Not Prime\n";
  } else if (N % 2 != 0 && N % 3 != 0 && N % 5 != 0) {
    cout << "Prime\n";
  } else if (N == 2 || N == 3 || N == 5) {
    cout << "Prime\n";
  } else {
    cout << "Not Prime\n";
  }
}
