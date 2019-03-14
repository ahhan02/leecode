#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> combine(string letter, vector<string> result) {
  if (result.size() == 0) {
    for (int i = 0; i < letter.size(); ++i) {
      // result.push_back(letter[i] + "");
      string s;
      s = letter[i];
      result.push_back(s);
    }
    return result;
  }

  vector<string> tmpResult;
  for (int i = 0; i < result.size(); ++i) {
    string s = result[i];
    for (int j = 0; j < letter.size(); ++j) {
      tmpResult.push_back(s + letter[j]);
    }
  }

  return tmpResult;
}

vector<string> letterCombinations(string digits) {
  map<char, string> mCharString;
  mCharString['2'] = "abc"; mCharString['3'] = "def";
  mCharString['4'] = "ghi"; mCharString['5'] = "jkl";
  mCharString['6'] = "mno"; mCharString['7'] = "pqrs";
  mCharString['8'] = "tuv"; mCharString['9'] = "wxyz";

  vector<string> res;
  for (int i = 0; i < digits.size(); ++i) {
    res = combine(mCharString[digits[i]], res);
  }

  return res;
}

int main() {
  string digits;
  cin >> digits;
  vector<string> res = letterCombinations(digits);
  for (string s : res) {
    cout << s << endl;
  }
  return 0;
}
