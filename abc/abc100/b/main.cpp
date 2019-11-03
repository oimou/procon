#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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

int main () {
  int D = getint();
  int N = getint();
  int h = (D == 0) ? 1 : ((D == 1) ? 100 : 10000);

  printf("%d\n", h * (N == 100 ? N + 1 : N));
}
