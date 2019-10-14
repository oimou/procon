#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  vector<int> n(3);
  int K;
  cin >> n.at(0) >> n.at(1) >> n.at(2) >> K;
  sort(n.begin(), n.end());
  cout << n.at(0) + n.at(1) + n.at(2) * pow(2, K);
}

/*
3つの数字の大小関係を，
\begin{equation}
\label{abc}
A \leq B \leq C
\end{equation}
と仮定しても一般性を失わない。

$n$回の操作を終えた後の3つの数字の合計としてありうる最大の値を$s_n$とおくと，$s_n$は，
\begin{equation}
S = \{\ 2^a A + 2^b B + 2^c C \ |\ a,b,c \mbox{は非負整数}, a + b + c = n\ \}
\end{equation}
によって定まる集合$S$の要素のうち最大のものであり，並び替え不等式より，
\begin{equation}
s_n = A + B + 2^n C
\end{equation}
である。
*/
