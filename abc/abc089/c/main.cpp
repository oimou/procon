#include <bits/stdc++.h>

using namespace std;

int main () {
  int N;
  cin >> N;

  long long a[5] = {0, 0, 0, 0, 0};
  while (N--) {
    string s;
    cin >> s;
    switch (s.at(0)) {
      case 'M': a[0]++; break;
      case 'A': a[1]++; break;
      case 'R': a[2]++; break;
      case 'C': a[3]++; break;
      case 'H': a[4]++; break;
    }
  }

  long long res = 0;
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      for (int k = j + 1; k < 5; k++)
        res += a[i] * a[j] * a[k];

  cout << res << "\n";
}
