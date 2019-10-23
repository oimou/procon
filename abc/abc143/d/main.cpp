#include <bits/stdc++.h>

using namespace std;

int input () { int x; cin >> x; return x; }

int main () {
  int N, count;
  vector<int> L;

  cin >> N;

  for (int i = 0; i < N; i++) L.push_back(input());

  sort(L.begin(), L.end());

  for (auto ib = L.end() - 1; ib >= L.begin(); ib--) {
    for (auto ia = ib - 1; ia >= L.begin(); ia--) {
      auto ic_upper_limit = lower_bound(ib, L.end(), *ia + *ib);
      count += distance(ib, ic_upper_limit) - 1;
    }
  }

  cout << count << "\n";
}
