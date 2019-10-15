#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
using Set = multiset<long>;

bool is_prime (long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  if (n == 3) return true;

  long sqrtn = sqrt(n);

  for (long i = 2; i < sqrtn + 1; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

Set get_prime_factors (long n) {
  long sqrtn = sqrt(n);
  Set prime_factors;

  for (long i = 1; i < sqrtn + 1; i++) {
    if (n % i != 0) continue;

    long I = n / i;

    if (is_prime(i)) prime_factors.insert(i);
    if (is_prime(I)) prime_factors.insert(I);
  }

  return prime_factors;
}

int main () {
  long A, B;
  cin >> A >> B;

  Set p1 = get_prime_factors(A);
  Set p2 = get_prime_factors(B);
  Set S;

  set_intersection(
    p1.begin(), p1.end(),
    p2.begin(), p2.end(),
    inserter(S, S.end())
  );

  S.insert(1);

  cout << S.size() << endl;
}

/*
$A$と$B$の公約数の集合を$R$とおき，$A$と$B$の共通の素因数の集合と$\{1\}$との和集合を$S$とおく。
すなわち，たとえば$A = 12, B = 18$のときは，
\[
    R = \{1, 2, 3, 6\}, S = \{1, 2, 3\}
\]
である。

$R$の部分集合でその要素が対ごとに素であるような集合を「問題の集合」と呼ぶことにし，
「問題の集合」のうち要素の個数が最大のものを$R_0$とおくと，
$R_0$の要素の個数が求める値である。

$R, S$に対して次が成り立つ：
\begin{quote}
    性質 i) $S \subset R$ \\
    性質 ii) $R$に含まれる任意の合成数$c$について，$c$の素因数はすべて$S$に含まれる
\end{quote}

性質 i)について，$p \in S$ならば$p$は$A$も$B$も割り切るので$p \in R$，ゆえに$S \subset R$である。

性質 ii)について，$R$に含まれる任意の合成数$c$とその任意の素因数$p$をとると，
$p$が$c$を割り切ることと，$c$が$A$も$B$も割り切ることから，$p$は$A$も$B$も割り切る。
したがって$p$は$A$と$B$の共通の素因数なので，$p \in S$である。
よって性質 ii)が成り立つ。

ここで，$R_0$に合成数$c$が含まれると仮定すると，
$R_0$から$c$を除いて代わりに$c$の素因数を含めた集合を$R_0'$とおけば，
性質 ii)によって$R_0'$もまた「問題の集合」であるが，その要素の個数は$R_0$より多いので，
$R_0$の定義に矛盾する。よって$R_0$は合成数を含まない。

したがって，$R_0$は$R$に含まれる素因数の集合と$\{1\}$との和集合であり，
性質 i)によって$R_0 = S$である。
*/
