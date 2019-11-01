#include <bits/stdc++.h>

using namespace std;

// assume that A is sorted in ascending order.
int binary_search (int A[], int n, int x) {
  // set a range to look up as a half-open interval: [left, right)
  int i_left = 0;
  int i_right = n;

  while (i_left < i_right) {
    int i_mid = (i_left + i_right) / 2;
    int m = A[i_mid];
    if (m == x) return i_mid;
    else if (m < x) i_left = i_mid + 1;
    else if (m > x) i_right = i_mid;
  }
  return -1;
}

int main () {
  int n;
  scanf("%d", &n);

  int S[n];
  for (int i = 0; i < n; i++) scanf("%d", &S[i]);

  int q;
  scanf("%d", &q);

  int cnt = 0;
  while (q--) {
    int t;
    scanf("%d", &t);
    cnt += (binary_search(S, n, t) != -1);
  }

  printf("%d\n", cnt);
}
