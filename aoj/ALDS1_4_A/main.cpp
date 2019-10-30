#include <bits/stdc++.h>

using namespace std;

int linear_search (int S[], int n, int x) {
  // Set a sentinel value
  S[n] = x;

  int i = 0;
  while (S[i] != x) i++;

  return i != n;
}

int main () {
  int n;
  scanf("%d", &n);

  int S[n + 1];
  for (int i = 0; i < n; i++) scanf("%d", &S[i]);

  int q;
  scanf("%d", &q);

  int cnt = 0;
  while (q--) {
    int t;
    scanf("%d", &t);
    cnt += linear_search(S, n, t);
  }

  printf("%d\n", cnt);
}
