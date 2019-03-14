#include <iostream>
#include <string>
#include <vector>
using namespace std;

void backtrack(vector<string>& ans, string cur,
    int open, int close, int max) {
  cout << "cur: " << cur << " open: " << open <<
    " close: " << close << endl;

  if (cur.size() == 2 * max) {
    ans.push_back(cur);
    return;
  }

  if (open < max) {
    backtrack(ans, cur+'(', open+1, close, max);
  }

  if (close < open) {
    backtrack(ans, cur+')', open, close+1, max);
  }
}


vector<string> generateParenthesis(int n) {
  vector<string> ans;
  backtrack(ans, "", 0, 0, n);
  return ans;
}


int main() {
  int n;
  cin >> n;
  vector<string> ans = generateParenthesis(n);
  for (string s : ans) {
    cout << s << endl;
  }
  return 0;
}
