#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct point {
  int x;
  int y;
  int min;
};

using points_2d = vector<vector<point>>;
using point_and_step = pair<point *, int>;

point * is_point_unresolved (points_2d & board, int x, int y) {
  if (0 <= y && y < board.size() && 0 <= x && x < board.at(y).size()) {
    point * p = &board.at(y).at(x);
    if (p->min == -1) return p;
  }
  return nullptr;
}

void lookup (points_2d & board, queue<point_and_step> & que, point * p, int step) {
  point * unresolved;
  int pos[4][2] = {
    p->x,     p->y - 1,
    p->x,     p->y + 1,
    p->x - 1, p->y,
    p->x + 1, p->y
  };

  for (int i = 0; i < 4; i++) {
    if (unresolved = is_point_unresolved(board, pos[i][0], pos[i][1])) {
      unresolved->min = step + 1;
      que.push(make_pair(unresolved, step + 1));
    }
  }
}

int main () {
  int R, C, sy, sx, gy, gx;

  cin >> R >> C >> sy >> sx >> gy >> gx;

  points_2d board(R, vector<point>(C));
  string line;

  for (int y = 0; y < R; y++) {
    cin >> line;

    for (int x = 0; x < C; x++) {
      board.at(y).at(x) = point{x, y, (line[x] == '#' ? -2 : -1)};
    }
  }

  point * start = &board.at(sy - 1).at(sx - 1);
  point * goal  = &board.at(gy - 1).at(gx - 1);
  queue<point_and_step> que;

  start->min = 0;
  que.push(make_pair(start, 0));

  while (!que.empty()) {
    point_and_step p = que.front();
    que.pop();

    if (p.first == goal) break;

    lookup(board, que, p.first, p.second);
  };

  cout << goal->min << endl;
}

// void print_board (points_2d & board) {
//   for (int y = 0; y < board.size(); y++) {
//     for (int x = 0; x < board.at(y).size(); x++) {
//       point * p = &board.at(y).at(x);
//       cout << (p->min == -2 ? "#" : ".")
//            << "(" << p->min << ")"
//            << "\t";
//     }
//     cout << endl;
//   }
// }
