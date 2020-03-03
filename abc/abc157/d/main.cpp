#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node * parent;
};

struct UnionFindForest {
  map<int, Node *> nodes;

  UnionFindForest() = default;

  void make_set (int i) {
    Node * node = (Node *) malloc(sizeof(Node));
    nodes.insert(make_pair(i, node));
    node->parent = node;
  }

  void unite (int ix, int iy) {
    Node * x = nodes.at(ix);
    Node * y = nodes.at(iy);
    Node * xRoot = find(x);
    Node * yRoot = find(y);
    xRoot->parent = yRoot;
  }

  Node * find (Node * x) {
    if (x->parent == x) {
      return x;
    } else {
      return find(x->parent);
    }
  }

  bool compare (int ix, int iy) {
    Node * x = nodes.at(ix);
    Node * y = nodes.at(iy);
    return find(x) == find(y);
  }
};

/**
 * main
 */
int main () {
  UnionFindForest uff;

  uff.make_set(1);
  uff.make_set(2);

  cout << uff.compare(1, 2) << '\n';

  uff.unite(1, 2);

  cout << uff.compare(1, 2) << '\n';
}
