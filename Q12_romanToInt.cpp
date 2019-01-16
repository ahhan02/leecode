#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s) {
  map<string, int> romanToInt;
  romanToInt["I"] = 1; romanToInt["IV"] = 4; romanToInt["V"] = 5;
  romanToInt["IX"] = 9; romanToInt["X"] = 10; romanToInt["XL"] = 40;
  romanToInt["L"] = 50; romanToInt["XC"] = 90; romanToInt["C"] = 100;
  romanToInt["CD"] = 400; romanToInt["D"] = 500; romanToInt["CM"] = 900;
  romanToInt["M"] = 1000;
  int res = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (i < s.size() - 1 && romanToInt[s.substr(i, 2)]) {
      res += romanToInt[s.substr(i, 2)];
      i++;
    } else {
      // res += romanToInt[s[i]];
      res += romanToInt[s.substr(i, 1)];
    }
  }

  return res;
}

int main() {
  string s;
  cin >> s;
  cout << romanToInt(s) << endl;
  return 0;
}
