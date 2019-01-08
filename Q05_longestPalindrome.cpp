#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int num = s.size();
    int dp_flag[1000][1000] = { 0 };
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            dp_flag[i][j] = 0;
        }
    }

    int start = 0, maxLen = 1;

    for (int i = 0; i < num; ++i) {
        dp_flag[i][i] = 1;
        if (i < num - 1 && s[i] == s[i+1]) {
            dp_flag[i][i+1] = 1;
            start = i;
            maxLen = 2;
      }
    }

    // s[i][j] = 1 if (s[i+1][j-1] == 1 and s[i] == s[j])
    for (int len = 3; len <= num; ++len) {
        for (int i = 0; i <= num-len; ++i) {
            int j = i + len - 1;
            if (dp_flag[i+1][j-1] && s[i] == s[j]) {
                dp_flag[i][j] = 1;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
}

int main()
{
  string s;
  cin >> s;
  cout << longestPalindrome(s) << endl;
  return 0;
}
