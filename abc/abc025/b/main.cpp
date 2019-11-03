#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
// #include <bits/stdc++.h>
#include <cstdio>

using namespace std;

/**
 * amazingly fast IO
 * NOTE: fread_unlocked does not work on macOS.
 */
const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
  if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
  return *ci++;
}
inline int getint() {
  int A = 0;
  if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
  else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
  return A;
}
inline void flus() {
  while (getcha() != ' ');
}

inline int clamp (int x, int a, int b) {
  return (x < a) ? a : ((x > b) ? b : x);
}

int main () {
  int N = getint();
  int A = getint();
  int B = getint();
  int ans = 0;

  while (N--) {
    bool east = (getcha() == 'E'); flus();
    int d = getint();
    ans += (east ? 1 : -1) * clamp(d, A, B);
  }

  if (ans > 0)
    printf("East %d\n", ans);
  else if (ans < 0)
    printf("West %d\n", -ans);
  else
    printf("0\n");
}
