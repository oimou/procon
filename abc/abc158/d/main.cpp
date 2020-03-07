#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * main
 */
int main () {
  string S_;
  cin >> S_;

  list<char> S;
  for (const char c : S_) {
    S.push_back(c);
  }

  int Q;
  cin >> Q;

  bool is_reversed = false;
  while (Q--) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
      is_reversed = !is_reversed;
    } else if (type == 2) {
      int F;
      char C;
      scanf("%d %c", &F, &C);

      if (!is_reversed && F == 1 || is_reversed && F == 2) {
        S.push_front(C);
      } else {
        S.push_back(C);
      }
    }
  }

  if (is_reversed) {
    for (auto it = S.rbegin(); it != S.rend(); it++) {
      printf("%c", *it);
    }
    printf("\n");
  } else {
    for (auto it = S.begin(); it != S.end(); it++) {
      printf("%c", *it);
    }
    printf("\n");
  }
}
