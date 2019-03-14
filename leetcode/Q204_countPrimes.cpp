#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int countPrimes1(int n) {
  int cnt = 0;
  for (int i = 2; i <= n; ++i) {
    if (isPrime(i)) {
      cnt++;
    }
  }

  return cnt;
}

int countPrimes(int n) {
  vector<bool> flag(n, true);
  for (int i = 2; i*i < n; ++i) {
    if (!flag[i]) {
      continue;
    }

    for (int j = i*i; j < n; j += i) {
      flag[j] = false;
    }
  }

  int cnt = 0;
  for (int i = 2; i < n; ++i) {
    if (flag[i]) {
      cnt++;
    }
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;
  cout << countPrimes(n) << endl;
  return 0;
}
