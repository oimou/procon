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

int bubble_sort (int A[], int N) {
  int cnt = 0;
  int i = 0;
  bool is_sorted = false;

  while (!is_sorted) {
    is_sorted = true;
    for (int j = N - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        swap(&A[j], &A[j - 1]);
        is_sorted = false;
        cnt++;
      }
    }
    i++;
  }

  return cnt;
}

int main () {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int cnt = bubble_sort(A, N);

  print_array(A, N);
  cout << cnt << "\n";
}
