#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <iterator>
#include <functional>

using namespace std;

int input () { int x; cin >> x; return x; }

int main () {
  int N;
  cin >> N;

  vector<int> L;
  for (int i = 0; i < N; i++) L.push_back(input());
  sort(L.begin(), L.end());

  for (auto & i : L) cout << i << " "; cout << endl;

  int count = 0;
  for (auto ic = L.end() - 1; ic >= L.begin() + 2; ic--) {
    for (auto ib = ic - 1; ib >= L.begin() + 1; ib--) {
      if (*ic >= 2 * *ib) continue;

      auto ix = lower_bound(L.begin(), ib, *ic - *ib, less<int>());
      count += distance(ix, ib);

      printf("ic-ib:%d ix:%d ib:%d ic:%d\n", *ic-*ib, *ix, *ib, *ic);
    }
  }

  cout << count << "\n";
}
