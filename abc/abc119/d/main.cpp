#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
using Integer = long long;

#define INFTY (Integer)100'000'000'000

Integer input () {
  Integer x;
  cin >> x;
  return x;
}

int main () {
  Integer A, B, Q;
  cin >> A >> B >> Q;

  vector<Integer> s;
  vector<Integer> t;

  for (Integer i = 0; i < A; i++) s.push_back(input());
  for (Integer i = 0; i < B; i++) t.push_back(input());

  auto f_plus = [&](Integer p) {
    if (p > s.back()) return INFTY;
    return *lower_bound(s.begin(), s.end(), p);
  };
  auto g_plus = [&](Integer p) {
    if (p > t.back()) return INFTY;
    return *lower_bound(t.begin(), t.end(), p);
  };
  auto f_minus = [&](Integer p) {
    if (p < s.front()) return -INFTY;
    return *--upper_bound(s.begin(), s.end(), p);
  };
  auto g_minus = [&](Integer p) {
    if (p < t.front()) return -INFTY;
    return *--upper_bound(t.begin(), t.end(), p);
  };

  for (Integer i = 0; i < Q; i++) {
    Integer p = input();
    Integer fp = f_plus(p);
    Integer fm = f_minus(p);
    Integer gp = g_plus(p);
    Integer gm = g_minus(p);
    Integer df = min(abs(fp - p), abs(fm - p));
    Integer dg = min(abs(gp - p), abs(gm - p));
    Integer d1 = max(abs(fp - p), abs(gp - p));
    Integer d2 = max(abs(fm - p), abs(gm - p));
    Integer d3 = 2 * min(df, dg) + max(df, dg);
    Integer d = min(min(d1, d2), d3);

    cout << d << endl;
  }
}
