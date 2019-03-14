#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
  // if (s == "") {
  //   return true;
  // }

  stack<char> st;
  for (char c : s) {
    if (!(c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')) {
      return false;
    }

    if (st.empty()) {
      st.push(c);
    } else {
      // if (c == st.top()) {
      if ((c == ')' && st.top() == '(') ||
          (c == ']' && st.top() == '[') ||
          (c == '}' && st.top() == '{')) {
        st.pop();
      } else {
        st.push(c);
      }
    }

    // cout << "st.size(): " << st.size() << endl;
  }

  if (st.empty()) {
    return true;
  }

  return false;
}

int main() {
  string s;
  cin >> s;
  cout << boolalpha << isValid(s) << endl;
  return 0;
}
