#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
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

int main() {
  int n;
  cin >> n;
  cout<< isPowerOfTwo(n) << endl;
  return 0;
}

