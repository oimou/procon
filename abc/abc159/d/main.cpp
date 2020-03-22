#include <bits/stdc++.h>
#define REP(i, a, b) for (ll i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const ll N_MAX = 2 * 1e5;

/**
 * main
 */
int main () {
  ll A[N_MAX];
  ll S[N_MAX + 1];
  ll N; cin >> N;

  for (ll i = 1; i <= N; i++) S[i] = 0;

  REP(i, 0, N) {
    cin >> A[i];
    S[A[i]]++;
  }

#ifdef DEBUG
  printf("--\n");
  for (ll i = 1; i <= N; i++) {
    printf("%lld %lld\n", i, S[i]);
  }
  printf("--\n");
#endif

  ll T[N_MAX + 1];
  ll sum = 0;

  for (ll i = 1; i <= N; i++) {
    ll k = S[i];

    T[i] = k * (k - 1) / 2;
    sum += T[i];
  }

  for (ll i = 0; i < N; i++) {
    ll j = A[i];
    ll k = S[j] - 1;
    ll l = k * (k - 1) / 2;

    printf("%lld\n", sum - T[j] + l);
  }
}
