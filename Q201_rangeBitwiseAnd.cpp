#include <iostream>
#include <bitset>
using namespace std;

int rangeBitwiseAnd1(int m, int n) {
  if (m == 0) {
    return 0;
  }

  if (n == INT_MAX) {
    n -= 1;
  }

  int res = m;
  for (int i = m+1; i <= n; ++i) {
    res &= i;
  }

  return res;
}

int rangeBitwiseAnd2(int m, int n) {
  int offset = 0;
  while (m != n) {
    m >>= 1;
    n >>= 1;
    offset++;
  }

  return m << offset;
}

int rangeBitwiseAnd(int m, int n) {
  while (n > m) {
    n &= (n - 1);
  }

  return n;
}

int main() {
  int m, n;
  cin >> m >> n;
  cout << rangeBitwiseAnd(m, n) << endl;
  return 0;
}


