#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int myAtoi(string str) {
    int res = 0, sign = 1;
    int len = str.size();
    bool preDigit = true;
    if (!((str[0] == ' ') || (str[0] == '-') || (str[0] == '+')
          || isdigit(str[0]))) return 0;

    int idx;
    for (int i = 0; i < len; ++i) {
      if (str[i] != ' ') {
        idx = i;
        break;
      }
    }

    for (int i = idx; i < len; ++i) {
      if (str[i] == '-') {
        sign = -1;
        preDigit = true;

        if (i+1 < len && !isdigit(str[i+1]))  {
          break;
        }
      } else if (str[i] == '+') {
        sign = 1;
        preDigit = true;

        if (i+1 < len && !isdigit(str[i+1]))  {
          break;
        }
      } else if (isdigit(str[i]) && preDigit) {
        int pop = str[i] - '0';
        // res = res * 10 + str[i] - '0';

        int signPop = sign * (str[i] - '0');
        int signRes = sign * res;

        if (signRes > INT_MAX/10 || (signRes == INT_MAX/10 && signPop > 7)) {
          return INT_MAX;
        }

        if (signRes < INT_MIN/10 || (signRes == INT_MIN/10 && signPop < -8)) {
          return INT_MIN;
        }

        res = res * 10 + pop;
        preDigit = true;

        if (i+1 < len && !isdigit(str[i+1])) {
          break;
        }
      } else {
        break;
      }
    }

    return sign * res;
}

int main() {
  string s;
  cin >> s;
  cout << myAtoi(s) << endl;
  return 0;
}
