#include <iostream>
#include <vector>
using namespace std;

int arrayPairSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  int res = 0;
  for (int i = 0; i < nums.size(); i+=2) {
    res += nums[i];
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
