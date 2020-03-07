#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

using FragmentList = list<int>;
using FragmentListPtr = shared_ptr<FragmentList>;
using Table = map<char, FragmentListPtr>;

int get_last_index (FragmentListPtr l) {
  int cnt = 0;
  for (auto it = l->begin(); it != l->end(); it++) {
    cnt += *it;
  }
  return cnt;
}

void insert (FragmentListPtr from, FragmentListPtr to, int i) {
  int acc;

  acc = 0;
  for (auto it = from->begin(); it != from->end(); it++) {
    if (i == acc + *it) {
      *next(it) += *it;
      from->erase(it);
      break;
    }
    acc += *it;
  }

  acc = 0;
  FragmentList::iterator it;
  for (it = to->begin(); it != to->end(); it++) {
    if (acc < i && i <= acc + *it) {
      break;
    }
    acc += *it;
  }

  *it -= (i - acc);
  to->insert(it, i - acc);
}

void show (Table & table, int l, int r) {
  int cnt = 0;
  for (auto item : table) {
    FragmentListPtr ls = item.second;
    int n_char = 0;
    for (auto it = ls->begin(); it != ls->end(); it++) {
      if (l <= n_char + *it && n_char + *it <= r) {
        cnt++;
        break;
      }

      n_char += *it;
    }
  }
  printf("%d\n", cnt);
}

void print_table (string S, Table & table) {
  cout << S << '\n';
  for (auto item : table) {
    if (item.second->size() == 0) continue;

    printf("%c: ", item.first);

    for (auto it = item.second->begin(); it != item.second->end(); it++) {
      printf("%d ", *it);
    }

    printf("\n");
  }

  printf("\n");
}

/**
 * main
 */
int main () {
  int N; cin >> N;
  string S; cin >> S;
  int Q; cin >> Q;

  Table table;

  // initialize a table
  for (char c = 'a'; c <= 'z'; c++) {
    FragmentListPtr l = make_shared<FragmentList>();
    table.insert(make_pair(c, l));
  }

  for (size_t i = 0; i < S.size(); i++) {
    char c = S.at(i);
    FragmentListPtr l = table.at(c);
    int last_index = get_last_index(l);
    l->push_back(i - last_index);
  }

  // print_table(S, table);

  while (Q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int i;
      char c_to;
      cin >> i >> c_to;

      i--;

      char c_from = S.at(i);
      if (c_from != c_to) {
        FragmentListPtr from = table.at(c_from);
        FragmentListPtr to = table.at(c_to);
        insert(from, to, i);
      }
      S[i] = c_to;
    } else {
      int l, r;
      cin >> l >> r;
      show(table, l - 1, r - 1);
    }

    // print_table(S, table);
  }
}
