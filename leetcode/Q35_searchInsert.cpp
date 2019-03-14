#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
  //
  int lh = 0, rh = nums.size() - 1;
  int mid = 0;
  while (lh <= rh) {
    mid = (lh + rh) / 2;
    if (nums[mid] < target) {
      lh = mid + 1;
    } else if (nums[mid] > target) {
      rh = mid - 1;
    } else {
      return mid;
    }

    cout << "mid: " << mid << endl;
    cout << "lh: " << lh << " rh: " << rh << endl;
  }

  return lh;
}

int main() {
  int elem, target;
  cin >> target;
  vector<int> nums;
  while (cin >> elem) {
    nums.push_back(elem);
  }
  int idx = searchInsert(nums, target);
  cout << "idx: " << idx << endl;
  return 0;
}
