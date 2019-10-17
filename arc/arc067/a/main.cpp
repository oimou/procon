#include <iostream>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

#define N_MAX 1000

bool is_combosite[N_MAX + 1];
bool is_prime (long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  if (is_combosite[n]) return false;

  long sqrtn = ceil(sqrt(n));

  for (long i = 2; i <= sqrtn; i++) {
    if (n % i == 0) {
      is_combosite[n] = true;
      return false;
    }
  }

  return true;
}

int count_factors (int n, int p) {
  int x = n;
  int count = 0;
  while (x % p == 0) {
    x /= p;
    count++;
  }
  return count;
}

void factorize_and_count (int m, vector<vector<int>> & table) {
  for (int i = 1; i <= m; i++) {
    if (m % i == 0 && is_prime(i)) table.at(m).at(i) = count_factors(m, i);
  }
}

int main () {
  int N;
  cin >> N;

  vector<vector<int>> table(N_MAX + 1, vector<int>(N_MAX + 1, 0));

  for (int i = 1; i <= N; i++) {
    factorize_and_count(i, table);
  }

  mp::cpp_int answer = 1;
  for (int i = 1; i <= N; i++) {
    int s = 0;
    for (int j = 1; j <= N; j++) {
      s += table.at(j).at(i);
    }
    answer *= mp::cpp_int(1 + s);
  }

  cout << (answer % mp::cpp_int(1'000'000'007)) << "\n";
}
