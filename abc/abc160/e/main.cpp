#include <bits/stdc++.h>
#define REP(i, a, b) for (ll i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

/**
 * main
 */
int main () {
  ll X; cin >> X;
  ll Y; cin >> Y;
  ll A; cin >> A;
  ll B; cin >> B;
  ll C; cin >> C;

  priority_queue<ll> P;
  priority_queue<ll> Q;
  priority_queue<ll> R;

  REP(i, 0, A) {
    ll input; cin >> input;
    P.push(input);
  }

  REP(i, 0, B) {
    ll input; cin >> input;
    Q.push(input);
  }

  REP(i, 0, C) {
    ll input; cin >> input;
    R.push(input);
  }

  // できるだけ赤色に着色するケース
  ll ans1 = 0;
  {
    priority_queue<ll> p(P);
    priority_queue<ll> q(Q);
    priority_queue<ll> r(R);
    ll x = X;
    ll y = Y;
    while (x > 0) {
      if (!r.empty()) {
        if (r.top() > p.top()) {
          ans1 += r.top(); r.pop();
        } else {
          ans1 += p.top(); p.pop();
        }
      } else {
        ans1 += p.top(); p.pop();
      }

      x--;
    }

    while (y > 0) {
      if (!r.empty()) {
        if (r.top() > q.top()) {
          ans1 += r.top(); r.pop();
        } else {
          ans1 += q.top(); q.pop();
        }
      } else {
        ans1 += q.top(); q.pop();
      }

      y--;
    }
  }

  // できるだけ緑色に着色するケース
  ll ans2 = 0;
  {
    ll x = X;
    ll y = Y;
    priority_queue<ll> p(P);
    priority_queue<ll> q(Q);
    priority_queue<ll> r(R);
    while (y > 0) {
      if (!r.empty()) {
        if (r.top() > q.top()) {
          ans2 += r.top(); r.pop();
        } else {
          ans2 += q.top(); q.pop();
        }
      } else {
        ans2 += q.top(); q.pop();
      }

      y--;
    }

    while (x > 0) {
      if (!r.empty()) {
        if (r.top() > p.top()) {
          ans2 += r.top(); r.pop();
        } else {
          ans2 += p.top(); p.pop();
        }
      } else {
        ans2 += p.top(); p.pop();
      }

      x--;
    }
  }

  cout << max(ans1, ans2) << endl;
}
