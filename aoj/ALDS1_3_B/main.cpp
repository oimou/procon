#include <bits/stdc++.h>
#define LEN 100005

using namespace std;

struct Proc {
  string name;
  int time;
};

Proc Q[LEN];
int head, tail;

void enqueue (Proc x) {
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

Proc dequeue () {
  Proc x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int main () {
  int n, q;
  cin >> n >> q;

  head = 0; tail = 0;
  while (n--) {
    Proc p;
    cin >> p.name >> p.time;
    enqueue(p);
  }

  int elapsed = 0;
  while (head != tail) {
    Proc p = dequeue();
    int dt = min(p.time, q);

    p.time -= dt;
    elapsed += dt;

    if (p.time == 0) {
      printf("%s %d\n", p.name.c_str(), elapsed);
    } else {
      enqueue(p);
    }
  }
}
