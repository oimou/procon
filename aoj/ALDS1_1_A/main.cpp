#include <iostream>
#include <vector>

using namespace std::literals;

void print (std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout
      << vec.at(i)
      << ((i == vec.size() - 1) ? "\n"s : " "s);
  }
}

using iterator = std::vector<int>::iterator;

int main () {
  int N;
  std::cin >> N;

  std::vector<int> a(N);

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> a.at(i);
  }

  print(a);

  for (int key_index = 1; key_index < N; key_index++) {
    int key = a.at(key_index);
    int j = key_index - 1;

    while (j >= 0 && a.at(j) > key) {
      a.at(j + 1) = a.at(j);

      j--;
    }

    a.at(j + 1) = key;

    print(a);
  }
}
