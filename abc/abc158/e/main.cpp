#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define RREP(i, a, b) for (int i = (a); i >= (b); --i)

using namespace std;
using ll = long long;

// P が 2 または 5 のとき
ll solve_1 (int N, int P, vector<int> S) {
  ll cnt = 0;

  RREP(i, N - 1, 0)
    if (S[i] % P == 0) cnt += i + 1;

  return cnt;
}

// P が 2 でも 5 でもないとき
ll solve_2 (int N, int P, vector<int> S) {
  ll cnt = 0;
  vector<int> table(P, 0);
  int U_i = 0;
  int base = 1;

  // 2.
  // この1は、U_i自体が（つまりiから最右端までの列が）割り切れる場合をカウントするために使われる。
  table[0] = 1;

  RREP(i, N - 1, 0) {
    U_i = (U_i + S[i] * base) % P;

    // 1.
    // table[U_i]には（具体的なjがどこかという情報は落ちているものの）U_{j+1} ≡ U_i であるようなjの個数が保存されている。
    // そのようなjを右端、iを左端とする列はPで割り切れる。
    // なぜならば、 U_{j+1} ≡ U_i より U_i - U_{j+1} はPで割り切れるため、解説PDFのいう条件が成り立つからである。
    cnt += table[U_i];

    table[U_i]++;
    base = (base * 10) % P;
  }

  return cnt;
}

/**
 * main
 */
int main () {
  int N, P; cin >> N >> P;
  string S_; cin >> S_;

  vector<int> S(N);
  REP(i, 0, N) S[i] = (S_[i] - '0') % P;

  cout << ((10 % P == 0) ? solve_1(N, P, S) : solve_2(N, P, S))
       << '\n';
}
