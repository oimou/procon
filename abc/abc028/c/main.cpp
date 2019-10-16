#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  vector<int> v = {
    A + B + C,
    A + B + D,
    A + B + E,
    A + C + D,
    A + C + E,
    A + D + E,
    B + C + D,
    B + C + E,
    B + D + E,
    C + D + E
  };
  nth_element(v.begin(), v.begin() + 2, v.end(), greater<int>());
  cout << v.at(2) << endl;
}

/*
所与の整数$A, B, C, D, E$は相異なるので，3数の選び方は次の10通り：
\begin{eqnarray*}
    &\{A, B, C\}, \\
    &\{A, B, D\}, \\
    &\{A, B, E\}, \\
    &\{A, C, D\}, \\
    &\{A, C, E\}, \\
    &\{A, D, E\}, \\
    &\{B, C, D\}, \\
    &\{B, C, E\}, \\
    &\{B, D, E\}, \\
    &\{C, D, E\}
\end{eqnarray*}
これらのうち和が3番目に大きいものが求める値である。
*/
