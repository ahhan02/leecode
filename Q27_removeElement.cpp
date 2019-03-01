#include <iostream>
#include <vector>
using namespace std;

int removeElement1(vector<int>& nums, int val) {
  // if (nums.size() == 0) {
  //   return 0;
  // }

  int i = 0, j = nums.size() - 1;
  while (i <= j) {
    while (i <= j && nums[i] != val) {
      ++i;
    }

    if (i == nums.size()) {
      return nums.size();
    }

    while (i <= j && nums[j] == val) {
      --j;
    }

    if (j == -1) {
      return 0;
    }

    if (i <= j) {
      nums[i++] = nums[j--];
    }
  }

  return i;
}

int removeElement(vector<int>& nums, int val) {
  int i = 0;
  for (int j = 0; j < nums.size(); ++j) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      ++i;
    }
  }
  return i;
}

int main() {
  int val;
  cin >> val;

  int elem;
  vector<int> nums;
  while (cin >> elem) {
    nums.push_back(elem);
  }

  cout << "val: " << val << endl;
  cout << "nums: ";
  for (int i = 0; i < nums.size(); ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;

  int len = removeElement(nums, val);
  cout << "len: " << len << endl;
  for (int i = 0; i < len; ++i) {
    cout << nums[i] << endl;
  }

  return 0;
}
