#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

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
  mp::cpp_int answer = 1;
  for (int p = 1; p <= N; p++) {
    if (!is_prime(p)) continue;
    int s = 0;
    for (int j = 1; pow(p, j) <= N; j++) s += floor(N / pow(p, j));
    answer *= mp::cpp_int(1 + s);
  }
  cout << (answer % mp::cpp_int(1'000'000'007)) << "\n";
}
