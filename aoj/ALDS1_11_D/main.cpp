#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

struct User;

using UserPtr = shared_ptr<User>;

struct User {
  int id;
  vector<UserPtr> friends;
  int color = -1;
};

void dfs (UserPtr user0, int color) {
  stack<UserPtr> S;
  S.push(user0);

  while (!S.empty()) {
    UserPtr user = S.top(); S.pop();

    user->color = color;

    for (const UserPtr fred : user->friends) {
      if (fred->color == -1) S.push(fred);
    }
  }
}

void assign_color (vector<UserPtr> & users) {
  int color = 0;
  for (const UserPtr user : users) {
    if (user->color != -1) continue;
    dfs(user, color);
    color++;
  }
}

/**
 * main
 */
int main () {
  int n, m;
  cin >> n >> m;

  vector<UserPtr> users(n);

  for (size_t i = 0; i < n; i++) users[i] = make_shared<User>();

  for (size_t i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;

    users[s]->friends.push_back(users[t]);
    users[t]->friends.push_back(users[s]);
  }

  assign_color(users);

  int q;
  cin >> q;

  for (size_t i = 0; i < q; i++) {
    int s, t;
    cin >> s >> t;

    if (users[s]->color == users[t]->color)
      printf("yes\n");
    else
      printf("no\n");
  }
}
