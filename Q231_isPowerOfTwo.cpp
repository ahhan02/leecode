#include <iostream>
#include <bitset>
using namespace std;

bool isPowerOfTwo1(int n) {
  if (n <= 0) {
    return false;
  }

  if (n == 1) {
    return true;
  }

  int cnt = 0;
  while (n) {
    cnt += n & 1;
    n >>= 1;
  }

  // cout << "cnt: " << cnt << endl;

  return cnt == 1 ? true : false;
}

bool isPowerOfTwo2(int n) {
  if (n <= 0) {
    return false;
  }

  return n & n-1 ? false : true;
}

bool isPowerOfTwo(int n) {
  if (n <= 0) {
    return false;
  }

  bitset<32> bsn(n);
  cout << bsn.count() << endl;
  return bsn.count() == 1 ? true : false;
}

int main() {
  int n;
  cin >> n;
  cout<< isPowerOfTwo(n) << endl;
  return 0;
}

