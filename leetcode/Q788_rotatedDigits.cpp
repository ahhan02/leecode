#include <iostream>
#include <sstream>
#include <map>
using namespace std;

bool isGood(int n) {
  map<char, char> c2c;
  c2c['0'] = '0';
  c2c['1'] = '1';
  c2c['2'] = '5';
  c2c['5'] = '2';
  c2c['6'] = '9';
  c2c['8'] = '8';
  c2c['9'] = '6';

  stringstream ss;
  ss << n;
  string sn = ss.str();
  string res = "";
  for (auto ch : sn) {
    if (ch == '3' || ch == '4' || ch == '7') {
      return false;
    }

    // res += ch;
    res += c2c[ch];
  }
  cout << "sn: " << sn << " res: " << res << endl;

  if (res == sn) {
    return false;
  }

  return true;
}

int rotatedDigits(int N) {
  int cnt = 0;
  for (int i = 2; i <= N; ++i) {
    if (isGood(i)) {
      cnt++;
      cout << i << endl;
    }
  }

  return cnt;
}

int main() {
  int N;
  cin >> N;
  cout << rotatedDigits(N) << endl;
  return 0;
}
