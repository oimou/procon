#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>

using namespace std;

bool flag[200000];

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
  long N = getint();
  int sum = 0;
  int y = -1;
  size_t input;
  for (size_t j = 0; j < N; j++) {
    input = getint();
    sum += input;

    if (flag[input]) y = input;
    else flag[input] = true;
  }

  if (y != -1) {
    // N * (N + 1) / 2 - x + y = sum
    int x = N * (N + 1) / 2 + y - sum;

    printf("%d %d\n", y, x);
  } else {
    printf("Correct\n");
  }
}
