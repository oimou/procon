#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

/**
 * amazingly fast input
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

struct Node;
struct Color {
  int n;
};

using NodePtr = shared_ptr<Node>;
using ColorPtr = shared_ptr<Color>;

struct Node {
  int id;
  ColorPtr color = nullptr;
  vector<NodePtr> followings;
  vector<NodePtr> blockings;

  int get_n_candidates () {
    int n_followings = 0;
    for (auto x : followings) {
      if (color == x->color) n_followings++;
    }

    int n_blockings = 0;
    for (auto x : blockings) {
      if (color == x->color) n_blockings++;
    }

    return color->n - n_followings - n_blockings - 1;
  }
};

void dfs (NodePtr node0, ColorPtr color) {
  stack<NodePtr> S;
  S.push(node0);

  while (!S.empty()) {
    NodePtr node = S.top(); S.pop();

    if (!node->color) {
      node->color = color;
      color->n++;
    }

    for (auto x : node->followings) {
      if (!x->color) S.push(x);
    }
  }
}

void assign_color (vector<NodePtr> nodes) {
  for (auto node : nodes) {
    if (node->color) continue;

    ColorPtr color = make_shared<Color>();
    dfs(node, color);
  }
}

/**
 * main
 */
int main () {
  int N = getint();
  int M = getint();
  int K = getint();

  vector<NodePtr> nodes(N);

  for (size_t i = 0; i < N; i++) {
    nodes[i] = make_shared<Node>();
    nodes[i]->id = i;
  }

  for (size_t i = 0; i < M; i++) {
    int A = getint();
    int B = getint();

    nodes[A-1]->followings.push_back(nodes[B-1]);
    nodes[B-1]->followings.push_back(nodes[A-1]);
  }

  for (size_t i = 0; i < K; i++) {
    int A = getint();
    int B = getint();

    nodes[A-1]->blockings.push_back(nodes[B-1]);
    nodes[B-1]->blockings.push_back(nodes[A-1]);
  }

  assign_color(nodes);

  for (size_t i = 0; i < N; i++) {
    printf("%d%c", nodes[i]->get_n_candidates(), (i == N - 1) ? '\n' : ' ');
  }
}
