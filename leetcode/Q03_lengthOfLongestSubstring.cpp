#include <iostream>
#include <string>
#include <set>
using namespace std;

int lengthOfLongestSubstring1(string s) {
    int maxLen = s.size() == 0 ? 0 : 1;

    int lh;
    for (int i = 0; i < s.size(); ++i) {
        lh = i;

        for (int j = i+1; j < s.size(); ++j) {
            string str = s.substr(lh, j-lh);
             // cout << str << endl;

            size_t found = str.find(s[j]);
            // cout << s[j] << ": " << (found == string::npos) << endl;

            if (found == string::npos) {
                if (maxLen < j-lh+1) {
                    maxLen = j - lh + 1;
                }
            } else {
                lh = j;
            }
        }

        if (s.size() - i < maxLen) {
          break;
        }
    }
    return maxLen;
}

int lengthOfLongestSubstring(string s) {
    set<char> ss;
    int maxLen = 0;
    int i = 0, j = 0, n = s.size();
    while (i < n && j < n) {
        if (!ss.count(s[j])) {        //
            ss.insert(s[j++]);
            maxLen = (j-i < maxLen) ? maxLen : j-i;
        } else {
            ss.erase(s[i++]);
        }
    }
    return maxLen;
}


int main() {
  string str1 = "";
  cin >> str1;
  int len = lengthOfLongestSubstring(str1);
  cout << "len: " << len << endl;
  return 0;
}
