#include <iostream>
using namespace std;

int reverse(int x) {
    // cout << "INT_MAX: " << INT_MAX << endl;
    // cout << "INT_MIN: " << INT_MIN << endl;
    // cout << "INT_MAX + 1 - 1: " << INT_MAX + 1 - 1 << endl;
    // cout << "INT_MIN - 1 + 1: " << INT_MIN - 1 + 1 << endl;
    // cout << "INT_MAX * 10 / 10: " << INT_MAX * 10 / 10 << endl;
    // cout << "INT_MIN * 10 / 10: " << INT_MIN * 10 / 10 << endl;

    // int sign = x > 0 ? 1 : -1;

    int res = 0;
    while(x) {
        // if overflow or not
        if (res * 10 / 10 != res) return 0;
            res = res * 10 + x % 10;
        x /= 10;
    }

    // return sign * res;
    return res;
}

int main() {
  int x;
  cin >> x;
  int res = reverse(x);
  cout << res << endl;
  return 0;
}
