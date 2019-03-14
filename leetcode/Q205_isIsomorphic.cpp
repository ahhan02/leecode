#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isIsomorphic1(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  map<char, char> mch, mch_r;
  for (int i = 0; i < s.size(); ++i) {
    mch[s[i]] = t[i];
    mch_r[t[i]] = s[i];
  }

  string o = "", o_r = "";
  for (int i = 0; i < s.size(); ++i) {
    o += mch[s[i]];
    o_r += mch_r[t[i]];
  }

  if (o == t && o_r == s) {
    return true;
  }

  return false;
}

bool isIsomorphic(string s, string t) {
  int slen = s.size(), tlen = t.size();
  if (slen != tlen) {
    return false;
  }

  int sarr[256] = { 0 }, tarr[256] = { 0 };
  for (int i = 0; i < slen; ++i) {
    if (sarr[s[i]] != tarr[t[i]]) {
      return false;
    } else {
      sarr[s[i]] = i + 1;
      tarr[t[i]] = i + 1;
    }
  }

  return true;
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << isIsomorphic(s, t) << endl;
  return 0;
}


