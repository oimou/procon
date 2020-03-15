#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
typedef long long ll;

static const int MAX_N = 100;
static const int MAX_M = 100;

int N;
int M;
bool is_water[MAX_N][MAX_M];

void xfs (int i0, int j0) {
  queue< pair<int, int> > q;

  is_water[i0][j0] = false;
  q.push(make_pair(i0, j0));

  while (!q.empty()) {
    pair<int, int> p = q.front(); q.pop();

    int i = p.first;
    int j = p.second;

    REP(di, -1, 2) {
      REP(dj, -1, 2) {
        int s = i + di;
        int t = j + dj;

        if (0 <= s && s < N && 0 <= t && t < M && is_water[s][t]) {
          is_water[s][t] = false; // mark it as visited when pushing; otherwise, space complexity bursts and you die.
          q.push(make_pair(s, t));
        }
      }
    }
  }
}

void solve () {
  ll cnt = 0;

  REP(i, 0, N) {
    REP(j, 0, M) {
      if (is_water[i][j]) {
        cnt++;
        xfs(i, j);
      }
    }
  }

  cout << cnt << endl;
}

/**
 * main
 */
int main () {
  cin >> N;
  cin >> M;

  REP(i, 0, N) {
    REP(j, 0, M) {
      char input; cin >> input;

      is_water[i][j] = (input == 'W');
    }
  }

  solve();
}
