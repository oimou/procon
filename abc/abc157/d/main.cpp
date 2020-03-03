#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

struct Node;

using NodePtr = shared_ptr<Node>;

struct Node {
  NodePtr parent;

  // additional properties
  set<int> friends;
  set<int> blocks;
};

struct DisjointSet {
  map<int, NodePtr> nodes;

  void make_set (int i) {
    NodePtr node = make_shared<Node>();
    nodes.insert(make_pair(i, node));
    node->parent = node;
  }

  void unite (int ix, int iy) {
    NodePtr x = nodes.at(ix);
    NodePtr y = nodes.at(iy);
    NodePtr xRoot = find(x);
    NodePtr yRoot = find(y);
    xRoot->parent = yRoot;
  }

  NodePtr find (NodePtr x) {
    if (x->parent == x) {
      return x;
    } else {
      return find(x->parent);
    }
  }

  bool compare (int ix, int iy) {
    NodePtr x = nodes.at(ix);
    NodePtr y = nodes.at(iy);
    return find(x) == find(y);
  }

  // additional properties
  NodePtr get_node (int i) {
    return nodes.at(i);
  }
};

/**
 * main
 */
int main () {
  DisjointSet djs;

  int N, M, K;

  cin >> N >> M >> K;

  for (size_t i = 1; i <= N; i++) {
    djs.make_set(i);
  }

  // friend
  for (size_t i = 2; i <= 1 + M; i++) {
    int a, b;
    cin >> a >> b;
    djs.unite(a, b);

    djs.get_node(a)->friends.insert(b);
    djs.get_node(b)->friends.insert(a);
  }

  // block
  for (size_t i = 1 + M + 1; i <= 1 + M + K; i++) {
    int c, d;
    cin >> c >> d;

    djs.get_node(c)->blocks.insert(d);
    djs.get_node(d)->blocks.insert(c);
  }

  for (size_t i = 1; i <= N; i++) {
    NodePtr node = djs.get_node(i);

    printf("%d:\n", i);

    printf("  friends:");
    for (int f : node->friends) {
      printf(" %d", f);

      if (djs.compare(i, f)) printf("*");
    }
    printf("\n");

    printf("  blocks:");
    for (int b : node->blocks) {
      printf(" %d", b);

      if (djs.compare(i, b)) printf("*");
    }
    printf("\n");
  }
}
