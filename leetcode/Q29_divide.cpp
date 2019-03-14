#include <iostream>
using namespace std;

int divide1(int dividend, int divisor) {
  // if (dividend == 0) {
  //   return 0;
  // }

  if (dividend == INT_MIN && divisor == INT_MIN) {
    return 1;
  }

  if (divisor == INT_MIN) {
    return 0;
  }

  if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
  }


  if (dividend == INT_MIN && divisor == 1) {
    return INT_MIN;
  }

  int res = 0;

  int flag1 = dividend > 0 && divisor > 0;
  int flag2 = dividend < 0 && divisor < 0;
  int flag3 = dividend > 0 && divisor < 0;
  int flag4 = dividend < 0 && divisor > 0;

  while (dividend) {
    // cout << "dividend: " << dividend << " divisor: " << divisor << endl;

    if ( (flag1 && dividend >= divisor) || (flag2 && dividend <= divisor) ) {
      dividend -= divisor;
      ++res;
    } else {
      break;
    }
  }

  while (dividend) {
    // if ( (flag3 && dividend >= -divisor) || (flag4 && -dividend >= divisor) ) {
    if ( (flag3 && dividend + divisor >= 0) ||
         (flag4 &&  dividend + divisor <= 0) ) {
      dividend += divisor;
      ++res;
    } else {
      break;
    }
  }

  if (flag3 || flag4) {
    return -res;
  }
  return res;
}

int divide(int dividend, int divisor) {
  int res = 0;
  if (dividend / divisor) {
    res = 1;
  }

  while (dividend / divisor) {
    cout << "0: dividend: " << dividend << " divisor: " << divisor << endl;
    res <<= 1;
    dividend >>= 1;
    cout << "1: dividend: " << dividend << " divisor: " << divisor << endl;
  }

  return res;
}

int main() {
  int dividend, divisor;
  cin >> dividend >> divisor;
  int res = divide(dividend, divisor);
  cout << res << endl;
  return 0;
}
