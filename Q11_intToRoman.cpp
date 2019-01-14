#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
  if (num < 1 || num > 3999) {
    return "";
  }

  int ints[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
    "X", "IX", "V", "IV", "I"};

  string res;
  for (int i = 0; i < 13; ++i) {
    while (num >= ints[i]) {
      res += romans[i];
      num -= ints[i];
    }
  }

  return res;
}


int main() {
  int num;
  cin >> num;
  cout << intToRoman(num) << endl;
  return 0;
}
