#include <iostream>

int main () {
  int N;
  int K;
  std::string S;

  std::cin >> N >> K;
  std::cin >> S;

  int i = 0;
  for (char & c : S) {
    std::cout << (i == K - 1 ? static_cast<char>(std::tolower(c)) : c);
    i++;
  }

  std::cout << std::endl;
}
