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

int selection_sort (int A[], int N) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) minj = j;
    }
    swap(&A[i], &A[minj]);
    if (i != minj) cnt++;
  }

  return cnt;
}

int main () {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  int cnt = selection_sort(A, N);

  print_array(A, N);
  cout << cnt << "\n";
}
