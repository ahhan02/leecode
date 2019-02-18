#include <iostream>
#include <string>
#include <vector>
using namespace std;

int strStr1(string haystack, string needle) {
  if (needle == "") {
    return 0;
  }

  // size_t found = haystack.find_first_of(needle);
  // cout << string::npos << endl;

  size_t found = haystack.find(needle);

  return found == string::npos ? -1 : found;
}

int strStr2(string haystack, string needle) {
  if (needle == "") {
    return 0;
  }

  if (haystack.size() < needle.size()) {
    return -1;
  }

  int i, j = 0;
  // for (i = 0; i < haystack.size() - needle.size(); ++i) {
  // for (i = 0; i <= haystack.size(); ++i) {
  for (i = 0; i < haystack.size(); ++i) {
    // cout << "i: " << i << "\tj: " << j << endl;
    if (j == needle.size()) {
      return i - j;
    }

    if (haystack[i] == needle[j]) {
      ++j;
    } else {
      i -= j;
      j = 0;
    }
  }

  if (j == needle.size()) {
    return i - j;
  }

  return -1;
}

vector<int> build_next(string ps) {
  vector<int> next(ps.size(), 0);
  next[0] = -1;

  // vector<int> next(ps.size(), -1);

  int k = -1;
  for (int j = 1; j < ps.size(); ++j) {
    while (k > -1 && ps[k+1] != ps[j]) {
      k = next[k];          // backtrack
    }

    if (ps[k+1] == ps[j]) {
      k++;
    }

    next[j] = k;
  }

  return next;
}

int strStr(string haystack, string needle) {
  if (needle == "") {
    return 0;
  }

  vector<int> next = build_next(needle);

  int k = -1;
  for (int i = 0; i < haystack.size(); ++i) {
    while (k > -1 && needle[k+1] != haystack[i]) {
      k = next[k];          // backtrack
    }

    if (needle[k+1] == haystack[i]) {
      k++;
    }

    if (k == needle.size() - 1) {
      return i - needle.size() + 1;
    }
  }

  return -1;
}

int main() {
  string haystack = "";
  string needle = "";
  // cin >> haystack;
  // cin >> needle;
  cout << strStr(haystack, needle) << endl;
  return 0;
}
