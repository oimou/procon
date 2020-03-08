#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const int INFTY = 1e5 + 1;

/**
 * main
 */
int main () {
  int A, B, M;
  cin >> A >> B >> M;

  vector<int> a(A);
  vector<int> b(B);
  int min_a = INFTY;
  int min_b = INFTY;

  REP(i, 0, A) {
    int input;
    scanf("%d", &input);
    a[i] = input;
    if (a[i] < min_a) min_a = a[i];
  }
  REP(i, 0, B) {
    int input;
    scanf("%d", &input);
    b[i] = input;
    if (b[i] < min_b) min_b = b[i];
  }

  int min_price = min_a + min_b;

  REP(i, 0, M) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);

    int t = a[x - 1] + b[y - 1] - c;
    if (t < min_price) min_price = t;
  }

  cout << min_price << '\n';
}
