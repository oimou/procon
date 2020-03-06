#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

struct Node;

using NodePtr = shared_ptr<Node>;

struct Node {
  int value;
  NodePtr parent = nullptr;
  NodePtr left = nullptr;
  NodePtr right = nullptr;
};

struct Tree {
  NodePtr root = nullptr;
};

void insert (Tree & tree, NodePtr z) {
  NodePtr y = nullptr;
  NodePtr x = tree.root;

  while (x) {
    y = x;
    if (z->value < x->value) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  if (!y) {
    tree.root = z;
  } else if (z->value < y->value) {
    y->left = z;
  } else {
    y->right = z;
  }
}

void inorder (NodePtr x) {
  if (!x) return;

  inorder(x->left);
  printf(" %d", x->value);
  inorder(x->right);
}

void preorder (NodePtr x) {
  if (!x) return;

  printf(" %d", x->value);
  preorder(x->left);
  preorder(x->right);
}

void print (Tree & tree) {
  inorder(tree.root);
  printf("\n");
  preorder(tree.root);
  printf("\n");
}

/**
 * main
 */
int main () {
  Tree tree;

  int n;
  cin >> n;

  while (n--) {
    string q;
    cin >> q;

    if (q == "insert") {
      NodePtr node = make_shared<Node>();
      int value; cin >> value;

      node->value = value;
      insert(tree, node);
    } else if (q == "print") {
      print(tree);
    }
  }
}
