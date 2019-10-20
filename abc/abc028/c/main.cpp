#include <iostream>
#include <cmath>

using namespace std;

int main () {
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  cout << max(E + D + A, E + C + B) << endl;
}
