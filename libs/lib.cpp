#include <bits/stdc++.h>

using namespace std;

template <typename T>
void swap (T * a, T * b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

template <typename T>
void print_array (T arr[], size_t n) {
  for (int i = 0; i < n; i++) printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
}
