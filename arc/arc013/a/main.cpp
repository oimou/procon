#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main () {
  int N, M, L, P, Q, R;

  cin >> N >> M >> L >> P >> Q >> R;

  auto count_packages = [&](int E_x, int E_y, int E_z) {
    return floor(N / E_x) * floor(M / E_y) * floor(L / E_z);
  };

  int max_packages = max({
    count_packages(P, Q, R),
    count_packages(P, R, Q),
    count_packages(Q, P, R),
    count_packages(Q, R, P),
    count_packages(R, P, Q),
    count_packages(R, Q, P)
  });

  cout << max_packages << endl;
}

/*
$x, y, z$軸をそれぞれタテ，ヨコ，高さの向きにとる。

荷物の向きの選び方の個数は，$x, y, z$軸に平行な辺の選び方の個数に等しいから，${}_3 \mathrm{P}_2 = 6$通りである。

このそれぞれに対して，$x, y, z$軸に平行な辺の長さを$E_x, E_y, E_z$とおくと，
$x, y, z$軸方向に並べることができる最大の個数はそれぞれ，
\[
    \left\lfloor \cfrac{N}{E_x} \right\rfloor,
    \left\lfloor \cfrac{M}{E_y} \right\rfloor,
    \left\lfloor \cfrac{L}{E_z} \right\rfloor
\]
であるから，梱包できる荷物の個数は，
\begin{equation}
    \label{packages}
    \left\lfloor \cfrac{N}{E_x} \right\rfloor
    \left\lfloor \cfrac{M}{E_y} \right\rfloor
    \left\lfloor \cfrac{L}{E_z} \right\rfloor
\end{equation}
である。
したがって，求める値は6通りのうちで最大の(\ref{packages})の値である。

*/
