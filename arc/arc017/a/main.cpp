#include <iostream>
#include <cmath>

using namespace std;

bool is_prime (long n) {
  if (n == 1) return false;
  if (n == 2) return true;

  long sqrtn = ceil(sqrt(n));

  for (long i = 2; i <= sqrtn; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

int main () {
  int N;
  cin >> N;
  cout << (is_prime(N) ? "YES" : "NO") << endl;
}

/*
$N$を2以上の整数とすると，$N$は素数あるいは合成数のいずれかである。
$N$が合成数ならば，2つの正整数$n_1, n_2\ (2 \leq n_1 \leq n_2 \leq N - 1)$を用いて
$N = n_1 n_2$と表すことができ，
$\lceil \sqrt{N} \rceil \geq \sqrt{N}$より$\lceil \sqrt{N} \rceil^2 \geq N$
であることに注意すれば，$n_1 \leq \lceil \sqrt{N} \rceil$である。
実際，$n_1 > \lceil \sqrt{N} \rceil$と仮定すると，
\begin{eqnarray*}
    n_1 n_2 &>&    \lceil \sqrt{N} \rceil n_2 \\
            &\geq& \lceil \sqrt{N} \rceil n_1 \\
            &>&    \lceil \sqrt{N} \rceil^2 \\
            &\geq& N
\end{eqnarray*}
となり矛盾する。

したがって，次が成り立つ：
\[
    \mbox{$N$が合成数} \Longrightarrow \mbox{$N$は$2 \leq n \leq \lceil \sqrt{N} \rceil$なる約数$n$を持つ}
\]
また，素数の定義から明らかに次が成り立つ：
\[
    \mbox{$N$が素数} \Longrightarrow \mbox{$N$は$2 \leq n \leq \lceil \sqrt{N} \rceil$なる約数$n$を持たない}
\]
したがって，次が成り立つ：
\[
    \mbox{$N$が素数} \Longleftrightarrow \mbox{$N$は$2 \leq n \leq \lceil \sqrt{N} \rceil$なる約数$n$を持たない}
\]
*/
