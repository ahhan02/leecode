#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> twoSum1(vector<int>& nums, int target) {
  //vector<int>::iterator it;
  //for (it = nums.begin(); it != nums.end(); ++it) {
  //  cout << *it << endl;
  //}
  vector<int> res;

  int len = nums.size();
  int i, j;
  for (i = 0; i < len; ++i) {
    for (j = i + 1; j < len; ++j) {
      if (nums[i] + nums[j] == target) {
        res.push_back(i);
        res.push_back(j);
        break;
      }
    }
  }

  return res;
}

vector<int> twoSum(vector<int>& nums, int target) {
  map<int, int> flagDict;
  vector<int> res;

  for (int i = 0; i < nums.size(); ++i) {
    int sub = target - nums[i];

    if (flagDict[sub]) {
      res.push_back(i);
      res.push_back(flagDict[sub]-1);

      break;
    }

    flagDict[nums[i]] = i + 1;
  }

  return res;
}

int main() {
  int nums[] = {2, 7, 11, 15};
  vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));

  int target = 18;

  vector<int> res = twoSum(nums_v, target);

  vector<int>::iterator it;
  for (it = res.begin(); it != res.end(); ++it) {
    cout << *it << endl;
  }

  return 0;
}
