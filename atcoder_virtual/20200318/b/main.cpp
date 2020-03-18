#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;
using Set = multiset<ll>;

bool is_prime (ll n) {
  if (n == 1) return false;
  if (n == 2) return true;
  if (n == 3) return true;

  ll sqrtn = sqrt(n);

  for (ll i = 2; i < sqrtn + 1; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

Set get_prime_factors (ll n) {
  ll sqrtn = sqrt(n);
  Set prime_factors;

  for (ll i = 1; i < sqrtn + 1; i++) {
    if (n % i != 0) continue;

    ll I = n / i;

    if (is_prime(i)) prime_factors.insert(i);
    if (is_prime(I)) prime_factors.insert(I);
  }

  return prime_factors;
}

ll gcd (ll x, ll y) {
  if (x % y == 0) return y;
  return gcd(y, x % y);
}

int main () {
  ll A, B;
  cin >> A >> B;

  ll g = gcd(A, B);
  Set S = get_prime_factors(g);

  S.insert(1);

  cout << S.size() << endl;
}
