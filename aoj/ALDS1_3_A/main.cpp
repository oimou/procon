#include <bits/stdc++.h>

using namespace std;
using Integer = long long;

int main () {
  stack<Integer> s;
  auto pop2 = [&]() {
    Integer first = s.top(); s.pop();
    Integer second = s.top(); s.pop();
    return make_pair(first, second);
  };

  while (true) {
    string x;
    cin >> x;
    if (cin.eof()) break;

    pair<Integer, Integer> p;
    switch (x[0]) {
      case '+':
        p = pop2();
        s.push(p.second + p.first);
        break;
      case '-':
        p = pop2();
        s.push(p.second - p.first);
        break;
      case '*':
        p = pop2();
        s.push(p.second * p.first);
        break;
      default:
        s.push(atoi(x.c_str()));
        break;
    }
  }

  cout << s.top() << "\n";
}
