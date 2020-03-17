#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

static const int INFTY = (1<<21);
static const int MAX = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

using namespace std;

/**
 * print an array in a row
 */
template <typename T>
void print_array (T arr[], size_t n) {
  for (int i = 0; i < n; i++) printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
}

int n;
int M[MAX][MAX];

int prim () {
  // index of the explorer node
  int explorer;

  // min weight needed when crossing to an unconquered node from the current MST
  int min_weight_to[n];

  int parent[n];
  int color[n];

  auto is_conquered = [&](int i) {
    return color[i] == BLACK;
  };

  auto is_connected = [&](int x, int y) {
    return M[x][y] != -1;
  };

  // initialize
  for (size_t i = 0; i < n; i++) {
    min_weight_to[i] = INFTY;
    parent[i] = -1;
    color[i] = WHITE;
  }

  // the first explorer is #0
  min_weight_to[0] = 0;

  for (int i = 0;; i++) {
    explorer = -1;

    // choose an explorer from among unconquered nodes
    int min_weight = INFTY;
    for (size_t candidate = 0; candidate < n; candidate++) {
      if (is_conquered(candidate)) continue;
      if (min_weight > min_weight_to[candidate]) {
        explorer = candidate;
        min_weight = min_weight_to[i];
      }
    }

    // finish if the conquest is all done
    if (explorer == -1) break;
    else color[explorer] = BLACK;

    // update min_weight along the border between the conquered area and the current MST
    for (size_t candidate = 0; candidate < n; candidate++) {
      if (is_conquered(candidate)) continue;
      if (M[explorer][candidate] != -1) {
        if (min_weight_to[candidate] > M[explorer][candidate]) {
          min_weight_to[candidate] = M[explorer][candidate];
          parent[candidate] = explorer;
          color[candidate] = GRAY;
        }
      }
    }
  }

  int sum = 0;
  for (size_t i = 0; i < n; i++) {
    if (parent[i] != -1) sum += M[i][parent[i]];
  }

  return sum;
}

/**
 * main
 */
int main () {
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      int input;
      cin >> input;
      M[i][j] = input;
    }
  }

  cout << prim() << '\n';
}
