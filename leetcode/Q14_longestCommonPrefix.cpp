#include <string>
#include <vector>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  int i, j;
  for (i = 0; i < strs[0].size(); ++i) {
    for (j = 1; j < strs.size(); ++j) {
      if (strs[j][i] != strs[0][i]) {
        // break;
        return strs[0].substr(0, i);
      }
    }
  }
  return strs[0].substr(0, i);
  // return "";
}

int main() {
  // string strs[] = {"flower", "flow", "flight"};
  string strs[] = {"dog", "rececar", "car"};
  vector<string> strs_vec(strs, strs+3);
  cout << longestCommonPrefix(strs_vec) << endl;
  return 0;
}
