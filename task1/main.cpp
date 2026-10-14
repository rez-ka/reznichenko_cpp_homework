#include <iomanip>
#include <iostream>

double Average(const int* a, int n) {
  double s = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i];
  }
  s /= n;
  return s;
}

void MinMax(const int* a, int n, int& mi, int& ma) {
  mi = a[0];
  ma = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] < mi) {
      mi = a[i];
    } else if (a[i] > ma) {
      ma = a[i];
    }
  }
}

int Negative(const int* a, int n) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      ++cnt;
    }
  }
  return cnt;
}

int main() {
  int n;
  std::cin >> n;
  int* data = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> data[i];
  }
  double avg = Average(data, n);
  std::cout << std::fixed << std::setprecision(1) << avg << '\n';
  int mi = 0, ma = 0;
  MinMax(data, n, mi, ma);
  std::cout << mi << ' ' << ma << '\n';
  int cnt_neg = Negative(data, n);
  std::cout << cnt_neg << '\n';
  delete[] data;
  return 0;
}
