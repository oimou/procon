#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

static const int MAX = 200000;
static const int WHITE = 0;
static const int RED = 1;
static const int BLUE = 2;

void paint (vector<int> * adj, vector<int> & color, vector<int> & reds, vector<int> & blues) {
  stack<pair<int, int>> S;

  S.push(make_pair(0, RED));

  while (!S.empty()) {
    pair<int, int> p = S.top(); S.pop();
    int u = p.first;
    int col = p.second;

    if (color[u] == WHITE) {
      color[u] = col;

      if (col == RED) reds.push_back(u);
      if (col == BLUE) blues.push_back(u);
    } else {
      continue;
    }

    REP(i, 0, adj[u].size()) {
      int v = adj[u][i];

      // use BLUE and RED alternately
      S.push(make_pair(v, (col == RED) ? BLUE : RED));
    }
  }
}

/**
 * print an array in a row
 */
template <typename T>
void print_array (T arr[], size_t n) {
  for (int i = 0; i < n; i++) printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
}

/**
 * main
 */
int main () {
  vector<int> adj[MAX];
  vector<int> p(MAX);
  vector<int> color(MAX);
  vector<int> reds;
  vector<int> blues;

  int N; cin >> N;

  REP(i, 0, N - 1) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  REP(i, 0, N) color[i] = WHITE;

  paint(adj, color, reds, blues);

  if (reds.size() > N / 3 && blues.size() > N / 3) {
    vector<int> r0;
    vector<int> r1;
    vector<int> r2;

    REP(i, 1, N + 1) {
      if (i % 3 == 0) r0.push_back(i);
      if (i % 3 == 1) r1.push_back(i);
      if (i % 3 == 2) r2.push_back(i);
    }

    auto it_r0 = r0.begin();
    auto it_r1 = r1.begin();
    auto it_r2 = r2.begin();

    REP(i, 0, reds.size())
      p[reds[i]] = (it_r1 == r1.end()) ? *(it_r0++) : *(it_r1++);
    REP(i, 0, blues.size())
      p[blues[i]] = (it_r2 == r2.end()) ? *(it_r0++) : *(it_r2++);
  } else {
    vector<int> r0;
    vector<int> rX;

    REP(i, 1, N + 1) {
      if (i % 3 == 0) r0.push_back(i);
      if (i % 3 != 0) rX.push_back(i);
    }

    auto it_r0 = r0.begin();
    auto it_rX = rX.begin();

    if (reds.size() <= N / 3) {
      REP(i, 0, reds.size())
        p[reds[i]] = *(it_r0++);
      REP(i, 0, blues.size())
        p[blues[i]] = (it_r0 == r0.end())? *(it_rX++) : *(it_r0++);
    } else {
      REP(i, 0, blues.size())
        p[blues[i]] = *(it_r0++);
      REP(i, 0, reds.size())
        p[reds[i]] = (it_r0 == r0.end())? *(it_rX++) : *(it_r0++);
    }
  }

  print_array(p.data(), N);
}
