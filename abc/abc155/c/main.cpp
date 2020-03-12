#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const string SENTINEL = "";

/**
 * main
 */
int main () {
  ll N; cin >> N;

  // read: O(N)
  vector<string> freq;
  while (N--) {
    char S[11]; scanf("%s", S);

    freq.push_back(string(S));
  }

  // sort: O(NlogN)
  sort(freq.begin(), freq.end());
  freq.push_back(SENTINEL);

  // obtain the max count: O(N)
  string prev = "";
  ll cnt = 0;
  ll m = 0;
  for (auto item : freq) {
    if (prev != item) {
      m = max(m, cnt);
      cnt = 1;
    } else {
      cnt++;
    }

    prev = item;
  }

  // print only items whose count is equal to m: O(N)
  prev = "";
  cnt = 0;
  for (auto item : freq) {
    if (prev != item) {
      if (cnt == m) printf("%s\n", prev.c_str());
      cnt = 1;
    } else {
      cnt++;
    }

    prev = item;
  }
}
