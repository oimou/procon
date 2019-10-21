#include <iostream>
#include <string>

using namespace std;

int main () {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  int dx = tx - sx;
  int dy = ty - sy;

  cout << string(dx, 'R') << string(dy, 'U')
       << string(dx, 'L') << string(dy, 'D')
       << 'L' << string(dy + 1, 'U') << string(dx + 1, 'R') << 'D'
       << 'R' << string(dy + 1, 'D') << string(dx + 1, 'L') << 'U'
       << "\n";
}
