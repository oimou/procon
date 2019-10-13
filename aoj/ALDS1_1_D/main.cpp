#include <iostream>
#include <cmath>

using namespace std::literals;

int main () {
  int n;
  long min_R;
  long max_diff = 0 - std::pow(10, 9);

  std::cin >> n;
  std::cin >> min_R;

  for (int i = 1; i < n; i++) {
    long R;
    std::cin >> R;

    max_diff = std::max(R - min_R, max_diff);

    if (R < min_R) min_R = R;
  }

  std::cout << max_diff << std::endl;
}
