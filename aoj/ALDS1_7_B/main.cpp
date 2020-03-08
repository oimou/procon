#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;

struct Node;

using NodePtr = shared_ptr<Node>;

struct Node {
  int id;
  int height;
  NodePtr parent = nullptr;
  NodePtr left = nullptr;
  NodePtr right = nullptr;
};

NodePtr get_root (NodePtr node) {
  NodePtr t = node;
  while (t->parent) t = t->parent;
  return t;
}

int get_depth (NodePtr node) {
  int cnt = 0;
  NodePtr t = node->parent;

  while (t) {
    cnt++;
    t = t->parent;
  }

  return cnt;
}

int set_height (NodePtr node) {
  int h1 = 0, h2 = 0;

  if (node->left) h1 = set_height(node->left) + 1;
  if (node->right) h2 = set_height(node->right) + 1;

  return (node->height = max(h1, h2));
}

/**
 * main
 */
int main () {
  int n; cin >> n;

  vector<NodePtr> nodes(n);

  REP(i, 0, n) {
    nodes[i] = make_shared<Node>();
    nodes[i]->id = i;
  }

  REP(i, 0, n) {
    int id, left, right;
    cin >> id >> left >> right;

    if (left != -1) {
      nodes[id]->left = nodes[left];
      nodes[left]->parent = nodes[id];
    }
    if (right != -1) {
      nodes[id]->right = nodes[right];
      nodes[right]->parent = nodes[id];
    }
  }

  set_height(get_root(nodes[0]));

  REP(i, 0, n) {
    NodePtr me = nodes[i];
    NodePtr parent = me->parent;
    NodePtr sibling = nullptr;

    if (parent) {
      if (parent->left == me) sibling = parent->right;
      else sibling = parent->left;
    }

    int id = me->id;
    int p = parent ? parent->id : -1;
    int s = sibling ? sibling->id : -1;
    int deg = (me->left ? 1 : 0) + (me->right ? 1 : 0);
    int dep = get_depth(me);
    int h = me->height;
    string type;

    if (!parent) {
      type = "root";
    } else {
      if (deg == 0) type = "leaf";
      else type = "internal node";
    }

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", id, p, s, deg, dep, h, type.c_str());
  }
}
