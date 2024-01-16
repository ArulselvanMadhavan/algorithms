#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <vector>

struct FenwickTree {
  std::vector<int> bit;
  int n;

  // Constructor
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0); // Init vector to 0
  }

  FenwickTree(std::vector<int> const &a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) {
      add(i, a[i]);
    }
  }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      ret += bit[r];
    }
    return ret;
  }

  // Implemented as: [0, r] - [0, l-1]
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int main() {
  std::cout << "---Fenwick Tree---" << std::endl;
  // Todo: manage ref with unique ptr
  auto b = std::vector<int>(10, 1);
  auto ft2 = FenwickTree(b);
  for (auto e : ft2.bit) {
    std::cout << e << std::endl;
  }
  std::cout << "sum:" << std::endl;
  std::cout << ft2.sum(4) << std::endl;
  std::cout << ft2.sum(6) << std::endl;
}
