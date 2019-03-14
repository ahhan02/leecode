#include <iostream>
#include <vector>
using namespace std;

int arrayPairSum1(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  int res = 0;
  for (int i = 0; i < nums.size(); i+=2) {
    res += nums[i];
  }

  return res;
}

int exist[20001] = { 0 };
int arrayPairSum(vector<int>& nums) {
  // int *exist = new int[20001];
  // int exist[20001] = { 0 };
  for (int i = 0; i < nums.size(); ++i) {
    exist[nums[i] + 10000]++;
  }

  int res = 0;
  bool odd = true;
  for (int i = 0; i < 20001; ++i) {
    while (exist[i]) {
      if (odd) {
        res += i - 10000;
      }

      odd = !odd;
      exist[i]--;
    }
  }

  return res;
}

int main() {
  int n;
  vector<int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }

  cout << arrayPairSum(nums) << endl;
  return 0;
}
