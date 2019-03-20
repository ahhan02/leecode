#include <iostream>
#include <string>
using namespace std;

int longestPalindrome(string s) {
  int cnt[52] = { 0 };
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] <= 'z' && s[i] >= 'a') {
      cnt[s[i]-'a']++;
    } else {
      // cnt[s[i]-'A']++;
      cnt[s[i]-'A'+26]++;
    }
  }

  int num = 0;
  for (int i = 0; i < 52; ++i) {
    cout << cnt[i] << " ";
    if (cnt[i] % 2) {
      num++;
    }
  }

  cout << "\nnum: " << num << endl;

  if (num >= 2) {
    return s.size()-num+1;
  }

  return s.size();
}

int main() {
  string s;
  cin >> s;
  cout << longestPalindrome(s) << endl;
  return 0;
}
