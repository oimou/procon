#include <bits/stdc++.h>

using namespace std;

struct Point {
  double x;
  double y;

  Point operator + (Point const q) const {
    return Point { x + q.x, y + q.y };
  }

  Point operator - (Point const q) const {
    return Point { x - q.x, y - q.y };
  }

  Point operator * (double k) const {
    return Point { x * k, y * k };
  }

  Point operator / (double k) const {
    return Point { x / k, y / k };
  }
};

void solve (Point p1, Point p2, size_t depth) {
  if (depth == 0) return;

  Point s, t, s_t, u;
  double cos60 = cos(M_PI / 3);
  double sin60 = sin(M_PI / 3);

  s = (p1 * 2 + p2) / 3;
  t = (p1 + p2 * 2) / 3;

  s_t = t - s;
  u = s + Point{
    s_t.x * cos60 - s_t.y * sin60,
    s_t.x * sin60 + s_t.y * cos60
  };

  solve(p1, s, depth - 1);
  printf("%f %f\n", s.x, s.y);
  solve(s, u, depth - 1);
  printf("%f %f\n", u.x, u.y);
  solve(u, t, depth - 1);
  printf("%f %f\n", t.x, t.y);
  solve(t, p2, depth - 1);
}

/**
 * main
 */
int main () {
  Point p1 {0, 0};
  Point p2 {100, 0};

  int n;
  cin >> n;

  printf("%f %f\n", p1.x, p1.y);
  solve(p1, p2, n);
  printf("%f %f\n", p2.x, p2.y);
}
