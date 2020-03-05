#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

struct Node;

using NodePtr = shared_ptr<Node>;

struct Node {
  int id;
  NodePtr parent = nullptr;
  NodePtr left_child = nullptr;
  NodePtr right_sib = nullptr;

  int get_depth () {
    int count = 0;
    NodePtr node = parent;
    while (node) {
      count++;
      node = node->parent;
    }
    return count;
  }

  string get_type () {
    if (!parent) return "root";
    if (!left_child) return "leaf";
    return "internal node";
  }

  string get_children () {
    string res = "[";
    NodePtr child = left_child;

    while (child) {
      res += to_string(child->id);
      if (child->right_sib) res += ", ";
      child = child->right_sib;
    }

    return res + "]";
  }
};

int input () {
  int tmp;
  cin >> tmp;
  return tmp;
}

/**
 * main
 */
int main () {
  int n = input();
  vector<NodePtr> nodes(n);

  for (int i = 0; i < n; i++) {
    NodePtr node = make_shared<Node>();
    node->id = i;
    nodes[i] = node;
  }

  for (int i = 0; i < n; i++) {
    int id = input();
    int k = input();
    NodePtr me = nodes.at(id);
    NodePtr child_prev;

    for (int j = 0; j < k; j++) {
      int c = input();
      NodePtr child = nodes.at(c);

      child->parent = me;
      if (j == 0) me->left_child = child;
      if (j > 0)  child_prev->right_sib = child;

      child_prev = child;
    }
  }

  for (int i = 0; i < n; i++) {
    NodePtr node = nodes.at(i);

    printf("node %d: ", i);
    printf("parent = %d, ", node->parent ? node->parent->id : -1);
    printf("depth = %d, ", node->get_depth());
    printf("%s, ", node->get_type().c_str());
    printf("%s", node->get_children().c_str());

    printf("\n");
  }
}
