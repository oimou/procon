#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const ll INFTY = ll(1e18) + 1;

int N;
ll K;
vector<ll> a;

// count the number of those elements whose values are <= x
inline ll get_count (ll x) {
  ll cnt = 0;

#ifdef DEBUG
  printf("\nx=%lld\n", x);
#endif

  REP(i, 0, N) {
    if (a[i] < 0) {
      // start from (i, N)
      int l = i;
      int r = N;

      while (r - l > 1) {
        int m = (l + r) / 2;

        if (a[i] * a[m] <= x) r = m;
        else l = m;
      }

      // [r, N) fulfills the condition
      cnt += N - r;

#ifdef DEBUG
      printf("a[i]=%lld, Δ=%d\n", a[i], N - r);
#endif
    } else {
      // start from (i, N)
      int l = i;
      int r = N;

      while (r - l > 1) {
        int m = (l + r) / 2;

        if (a[i] * a[m] <= x) l = m;
        else r = m;
      }

      // (i, l] fulfills the condition
      cnt += l - i;

#ifdef DEBUG
      printf("a[i]=%lld, Δ=%d\n", a[i], l - i);
#endif
    }
  }

#ifdef DEBUG
  printf("cnt=%lld\n", cnt);
#endif

  return cnt;
}

inline ll bs (ll left0, ll right0) {
  // start from (left0, right0)
  ll left = left0;
  ll right = right0;

  while (right - left > 1) {
    ll mid = (left + right) / 2;

    if (get_count(mid) < K) left = mid;
    else right = mid;
  }

  // (left0, left] fulfills the condition
  return left + 1;
}

/**
 * main
 */
int main () {
  cin >> N;
  cin >> K;

  a.resize(N);

  REP(i, 0, N) scanf("%lld", &a[i]);

  sort(a.begin(), a.end());

  cout << bs(-INFTY, INFTY) << endl;
}
