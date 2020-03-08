#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define RREP(i, a, b) for (int i = (a); i >= (b); --i)

using namespace std;
using ll = long long;

static const ll MAX = 1e9;

void input (vector<ll> & v, int N) {
  REP(i, 0, N) {
    ll x;
    scanf("%lld", &x);
    v[i] = x;
  }
  sort(v.begin(), v.end());
}

/**
 * print an array in a row
 */
template <typename T>
void print_array (T arr[], size_t n) {
  for (int i = 0; i < n; i++) printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
}

/**
 * main
 */
int main () {
  int N;
  cin >> N;

  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);

  input(A, N);
  input(B, N);
  input(C, N);

  vector<ll> nb(N + 1);
  ll acc = 0;

  nb[N] = 0;

  RREP(i_b, N - 1, 0) {
    ll b = B[i_b];

    auto it = lower_bound(C.begin(), C.end(), b + 1);
    int i_c = distance(C.begin(), it);
    acc += N - i_c;
    nb[i_b] = acc;
  }

  ll cnt = 0;

  RREP(i_a, N - 1, 0) {
    ll a = A[i_a];

    auto it = lower_bound(B.begin(), B.end(), a + 1);
    int i_b = distance(B.begin(), it);

    cnt += nb[i_b];
  }

  cout << cnt << '\n';
}
