#include <bits/stdc++.h>

using namespace std;

vector<int> init_L () {
  int N;
  cin >> N;

  vector<int> L;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    L.push_back(x);
  }

  sort(L.begin(), L.end());

  return L;
}

int main () {
  int cnt = 0;
  vector<int> L = init_L();

  for (auto ia = L.begin(); ia <= L.end() - 3; ia++) {
    for (auto ib = ia + 1; ib <= L.end() - 2; ib++) {
      auto il = (L.back() < *ia + *ib)
        ? L.end()
        : lower_bound(ib, L.end(), *ia + *ib);
      cnt += max((int)distance(ib + 1, il - 1) + 1, 0);
    }
  }

  cout << cnt << "\n";
}
