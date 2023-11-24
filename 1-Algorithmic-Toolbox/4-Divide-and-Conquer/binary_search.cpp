#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binarySearch(const vector<int> &a, int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x)
            return m;
        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
 
    return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
//  std::cout << "Input received" << std::endl ;
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binarySearch(a, 0, n - 1, b[i]) << ' ';
  }
}