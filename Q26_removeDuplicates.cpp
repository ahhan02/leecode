#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  if (nums.size() == 0) {
    return 0;
  }

  int idx = 1;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] != nums[i-1]) {
      nums[idx++] = nums[i];
    }
  }

  return idx;
}

int main() {
  //int a[] = {1, 1, 2};
  //vector<int> nums(a, a +3);
  int a[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  vector<int> nums(a, a+10);
  int len = removeDuplicates(nums);
  for (int i = 0; i < len; ++i) {
    cout << nums[i] << endl;
  }
  return 0;
}
