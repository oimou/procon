#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <algorithm>
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

int main () {
  int N = getint();
  int T = getint();

  int prev, curr, sum = 0;

  // A_1
  prev = getint();
  sum += prev;

  for (int i = 1; i < N; i++) {
    curr = getint();
    sum += max(curr - prev - T, 0);
    prev = curr;
  }

  printf("%d\n", curr + T - sum);
}
