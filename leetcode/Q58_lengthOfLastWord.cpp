#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
  int len = s.size(), cnt = 0;
  for (int i = len-1; i >= 0; --i) {
    if (isspace(s[i])) {
      continue;
    }

    while (isalpha(s[i])) {
      --i;
      ++cnt;
    }
    return cnt;
  }

  return 0;
}

int main() {
  string s;
  // cin >> s;
  getline(cin, s);
  cout << lengthOfLastWord(s) << endl;
  return 0;
}
