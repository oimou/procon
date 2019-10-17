#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define SQUARE(x) ((x)*(x))

using namespace std;

int main () {
  int x1, y1, r, x2, y2, x3, y3;
  cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

  bool red = !(x2 + r <= x1 && x1 <= x3 - r && y2 + r <= y1 && y1 <= y3 - r);
  bool blue;

  if (!red) {
    blue = true;
  } else {
    vector<int> d {
      SQUARE(x2 - x1) + SQUARE(y2 - y1),
      SQUARE(x3 - x1) + SQUARE(y2 - y1),
      SQUARE(x3 - x1) + SQUARE(y3 - y1),
      SQUARE(x2 - x1) + SQUARE(y3 - y1)
    };
    blue = !(*max_element(d.begin(), d.end()) <= SQUARE(r));
  }

  cout << (red ? "YES" : "NO") << "\n" << (blue ? "YES" : "NO") << "\n";
}
