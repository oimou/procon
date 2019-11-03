#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * amazingly fast input
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

/**
 * main
 */
int main () {
  double A = getint();
  double B = getint();
  double C = getint();
  double X = getint();

  int ans = 0;
  int a_max = min(floor(X / 500), A);
  for (int a = 0; a <= a_max; a++) {
    int b_min = max( ceil(X / 100 - 5 * a - C / 2), 0.0);
    int b_max = min(floor(X / 100 - 5 * a), B);
    ans += (b_max >= b_min) ? b_max - b_min + 1 : 0;
  }

  printf("%d\n", ans);
}
