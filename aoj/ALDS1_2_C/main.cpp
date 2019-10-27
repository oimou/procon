#include <bits/stdc++.h>

using namespace std;

struct Card {
  char suit;
  char value;
};

template <typename T>
void swap (T * a, T * b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

void print_array (Card arr[], size_t n) {
  for (int i = 0; i < n; i++)
    printf("%c%c%c", arr[i].suit, arr[i].value, (i == n - 1) ? '\n' : ' ');
}

void bubble_sort (Card A[], int N) {
  int i = 0;
  bool is_sorted = false;

  while (!is_sorted) {
    is_sorted = true;
    for (int j = N - 1; j >= i + 1; j--) {
      if (A[j].value < A[j - 1].value) {
        swap(&A[j], &A[j - 1]);
        is_sorted = false;
      }
    }
    i++;
  }
}

void selection_sort (Card A[], int N) {
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j].value < A[minj].value) minj = j;
    }
    swap(&A[i], &A[minj]);
  }
}

bool is_stable (Card S1[], Card S2[], int N) {
  for (int i = 0; i < N; i++) {
    if (S1[i].suit != S2[i].suit) return false;
  }
  return true;
}

int main () {
  int N;
  cin >> N;

  Card S1[N];
  Card S2[N];
  for (int i = 0; i < N; i++) {
    Card x;
    cin >> x.suit >> x.value;
    S1[i] = x;
    S2[i] = x;
  }

  bubble_sort(S1, N);
  selection_sort(S2, N);

  print_array(S1, N);
  cout << "Stable\n";
  print_array(S2, N);
  cout << ((is_stable(S1, S2, N)) ? "Stable" : "Not stable") << "\n";
}
