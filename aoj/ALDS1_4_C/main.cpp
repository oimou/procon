#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#define M 1'000'003
#define NIL "\0"

using namespace std;

inline int h1 (int x) {
  return x % M;
}

inline int h2 (int x) {
  return 1 + (x % (M - 1));
}

inline int h (int x, int i) {
  return (h1(x) + i * h2(x)) % M;
}

inline int to_code (char c) {
  if (c == 'A') return 0;
  if (c == 'T') return 1;
  if (c == 'G') return 2;
  if (c == 'C') return 3;
  throw "invalid input";
}

inline int op_to_key (string op) {
  int key = 1;
  for (auto c : op) {
    key *= to_code(c);
    key *= 4;
  }
  return key;
}

string storage[M];

void insert (string op) {
  int key = op_to_key(op);
  for (int i = 0; i < M; i++) {
    int hash = h(key, i);

    // insert it into an empty place.
    if (storage[hash] == NIL) {
      storage[hash].assign(op); // ????
      break;
    }

    // when it is already stored, stop trying to insert it.
    if (storage[hash] == op) {
      break;
    }
  }
}

bool find (string op) {
  int key = op_to_key(op);
  for (int i = 0; i < M; i++) {
    int hash = h(key, i);

    if (storage[hash] == op) {
      return true;
    }

    if (storage[hash] == NIL) {
      return false;
    }
  }

  // return false when the storage is full but `op` is not stored.
  return false;
}

/**
 * main
 */
int main () {
  int n;
  cin >> n;

  for (int i = 0; i < M; i++) storage[i] = NIL;

  while (n--) {
    string command, op;
    cin >> command >> op;

    if (command == "insert") insert(op);
    if (command == "find") {
      printf("%s\n", find(op) ? "yes" : "no");
    }
  }
}
