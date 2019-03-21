#include <iostream>
#include <string>
using namespace std;

int repeatedStringMatch1(string A, string B) {
  int cnt = 1;
  size_t found = A.find(B);
  string repA = A;

  cout << (found == string::npos) << endl;
  while (found == string::npos) {
    cnt++;
    repA += A;
    found = repA.find(B);

    cout << repA << endl;

    if (repA.size() > 10000) {
      return -1;
    }
  }

  return cnt;
}

int repeatedStringMatch(string A, string B) {
  int cnt = 1;
  int maxLen = 2 * A.size() + B.size();
  while (A.size() < maxLen) {
    size_t found = A.find(B);
    if (found == string::npos) {
      A += A;
      cnt++;
    } else {
      return cnt;
    }
  }

  return -1;
}

int main() {
  string A, B;
  cin >> A >> B;
  cout << repeatedStringMatch(A, B) << endl;
  return 0;
}
