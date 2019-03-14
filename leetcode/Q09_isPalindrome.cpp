#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool isPalindrome1(int x) {
  if (x < 0) {
    return false;
  }

  stringstream ss;
  ss << x;

  string s;
  ss >> s;

  // for (char x : s) {
  //   cout << x << endl;
  // }

  int len = s.size();
  int i, j;
  for(i = 0, j = len - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      break;
    }
  }

  if (i < j) {
    return false;
  }

  return true;
}

bool isPalindrome2(int x) {
  if (x < 0) {
    return false;
  }

  stringstream ss;
  ss << x;
  string s;
  ss >> s;

  int len = s.size();
  string firPart = s.substr(0, len/2);
  reverse(firPart.begin(), firPart.end());
  if (len % 2) {
    if (firPart == s.substr(len/2+1, len/2)) {
      return true;
    }
    return false;
  } else {
    if (firPart == s.substr(len/2, len/2)) {
      return true;
    }
    return false;
  }
}

bool isPalindrome(int x) {
  // if (x < 0) {
  if (x < 0 || (x % 10 == 0 && x)) {
    return false;
  }

  int res = 0;
  while (x > res) {
    res = res * 10 + x % 10;
    x /= 10;
  }

  // cout << "res: " << res << "\tx: " << x << endl;
  // if (x == res || x == res/10) {
  //   return true;
  // } else {
  //   return false;
  // }

  return x == res || x == res/10;
}


int main() {
  int x;
  cin >> x;
  cout << boolalpha << isPalindrome(x) << endl;
  return 0;
}
