#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

using namespace std;

static const int INFTY = 1e9 + 1;

int cnt = 0;

void merge (vector<int> & v, int left, int mid, int right) {
  vector<int> L;
  vector<int> R;

  copy(v.begin() + left, v.begin() + mid, back_inserter(L));
  copy(v.begin() + mid, v.begin() + right, back_inserter(R));

  // push a sentinel
  L.push_back(INFTY);
  R.push_back(INFTY);

  auto l = L.begin();
  auto r = R.begin();
  for (size_t i = left; i < right; i++) {
    cnt++;
    if (*l > *r) {
      v[i] = *r;
      r++;
    } else {
      v[i]= *l;
      l++;
    }
  }
}

// sort elements in [left, right)
void merge_sort (vector<int> & v, int left, int right) {
  if (left + 1 >= right) return;

  // divide
  int mid = (left + right) / 2;

  // solve
  merge_sort(v, left, mid);
  merge_sort(v, mid, right);

  // conquer
  merge(v, left, mid, right);
}

/**
 * print an array in a row
 */
template <typename T>
void print_array (T arr[], size_t n) {
  for (int i = 0; i < n; i++) printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
}

/**
 * main
 */
int main () {
  vector<int> v;
  int N;
  cin >> N;

  while (N--) {
    int input;
    cin >> input;
    v.push_back(input);
  }

  merge_sort(v, 0, v.size());

  print_array(v.data(), v.size());
  printf("%d\n", cnt);
}
