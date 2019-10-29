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

Node * list_search (Integer key) {}

void delete_node (Node * x) {}

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
    char command[11];
    Integer key;
    scanf("%s %d", command, &key);

    if ("insert" == string(command)) {
      insert(key);
    } else if ("delete" == string(command)) {
      delete_node(list_search(key));
    }
  }

  print_list();
}
