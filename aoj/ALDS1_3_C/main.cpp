#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

struct Node {
  Integer key;
  Node * prev;
  Node * next;
};

Node * nil;

void insert (Integer key) {
  Node * x = (Node *) malloc(sizeof(Node));;
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

Node * list_search (Integer key) {
  Node * cur = nil->next;
  while (cur->key != key) {
    if (cur == nil) break;
    cur = cur->next;
  }
  return cur;
}

void delete_node (Node * x) {
  if (x == nil) return;

  x->prev->next = x->next;
  x->next->prev = x->prev;
  free(x);
}

void delete_first () {
  delete_node(nil->next);
}

void delete_last () {
  delete_node(nil->prev);
}

void print_list () {
  Node * cur = nil->next;
  bool is_first_loop = true;
  while (true) {
    if (cur == nil) break;

    if (!is_first_loop) printf(" ");
    printf("%d", cur->key);

    cur = cur->next;
    is_first_loop = false;
  }
  printf("\n");
}

int main () {
  Integer n;
  cin >> n;

  nil = (Node *) malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;

  while (n--) {
    char command[20];
    Integer key;
    scanf("%s %d", command, &key);

    if (string(command) == "insert") {
      insert(key);
    } else if (string(command) == "delete") {
      delete_node(list_search(key));
    } else if (string(command) == "deleteFirst") {
      delete_first();
    } else if (string(command) == "deleteLast") {
      delete_last();
    }
  }

  print_list();
}
