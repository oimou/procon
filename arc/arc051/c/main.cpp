#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct ResidueClass {
  using Integer = long long;
  Integer value;
  Integer M = 1e9 + 7;

  ResidueClass (Integer x) {
    value = positive_mod(x, M);
  }

  ResidueClass operator + (ResidueClass const x) const {
    return ResidueClass { positive_mod(value + x.value, M) };
  }

  ResidueClass operator - (ResidueClass const x) const {
    return ResidueClass { positive_mod(value - x.value, M) };
  }

  ResidueClass operator * (ResidueClass const x) const {
    return ResidueClass { positive_mod(value * x.value, M) };
  }

  ResidueClass operator / (ResidueClass const x) const {
    ResidueClass x_inv = fast_pow(x, M - 2);
    return ResidueClass { positive_mod(value * x_inv.value, M) };
  }

  static ResidueClass factorial (ResidueClass n) {
    ResidueClass res(1);
    for (int i = n.value; i >= 1; i--) res = res * ResidueClass(i);
    return res;
  }

  static ResidueClass fast_pow (ResidueClass x, Integer n) {
    if (n == 0) return ResidueClass(1);
    if (n % 2 == 0) return fast_pow(x * x, n / 2);
    else return x * fast_pow(x, n - 1);
  }

  static Integer positive_mod (Integer a, Integer b) {
    Integer res = a % b;
    if (res < 0) res += b;
    return res;
  }
};

struct Item {
  int x;
  double log_x;
  int g;
  int cnt;
};

auto comp = [](auto & lh, auto & rh) {
  return lh.log_x + lh.cnt < rh.log_x + rh.cnt;
};

void f_A (vector<Item> & a) {
  min_element(a.begin(), a.end(), comp)->cnt++;
}

void print (vector<Item> & a, int A) {
  if (A != 1)
    sort(a.begin(), a.end(), comp);
  else
    sort(a.begin(), a.end(), [](auto & lh, auto & rh) {
      return lh.x < rh.x;
    });

  for (auto item : a) {
    ResidueClass r(item.x);
    r = r * ResidueClass::fast_pow(ResidueClass(A), item.cnt);
    printf("%d\n", r.value);
  }
}

/**
 * main
 */
int main () {
  int N, A, B;
  scanf("%d %d %d", &N, &A, &B);
  vector<Item> a(N);
  for (int i = 0; i < N; i++) {
    int x; scanf("%d", &x);
    double log_x = log(x) / log(A);
    a[i] = Item{ x, log_x, (int) floor(log_x), 0 };
  }

  if (A == 1) {
    print(a, A);
    return 0;
  }

  int const I = max_element(a.begin(), a.end(), [](auto & lh, auto & rh) {
    return lh.g < rh.g;
  })->g;
  int B0 = 0; for (auto item : a) B0 += I - item.g;
  int const b  = (B - B0) / N;
  int const B1 = (B - B0) % N;

  if (B > B0) {
    for (auto & item : a) item.cnt = - item.g + I + b;
    for (int i = 0; i < B1; i++) f_A(a);
  } else {
    for (int i = 0; i < B; i++) f_A(a);
  }

  print(a, A);
  return 0;
}
