#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());

  int sum, closeSum = nums[0]+nums[1]+nums[2];
  int lh, rh;
  for (int i = 0; i < nums.size(); ++i) {
    lh = i + 1;
    rh = nums.size() - 1;
    while (lh < rh) {
      sum = nums[i] + nums[lh] + nums[rh];
      cout << nums[i] << " " << nums[lh] << " " << nums[rh] << endl;
      cout << "sum: " << sum << endl;

      if (sum == target) {
        return sum;
      } else if (sum < target) {
        lh++;
      } else {
        rh--;
      }

      if (abs(sum-target) < abs(closeSum-target))
        closeSum = sum;
    }
  }

  return closeSum;
}

int main() {
  int a[] = {1, 1, 1, 0};
  int target = -100;
  vector<int> nums(a, a+4);
  cout << threeSumClosest(nums, target) << endl;
  return 0;
}
