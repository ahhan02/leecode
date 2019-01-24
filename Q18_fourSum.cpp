#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
  vector<vector<int> > res;

  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    int rest1 = target - nums[i];
    // cout << "rest1: " << rest1 << endl;

    for (int j = i + 1; j < nums.size(); ++j) {
      int rest2 = rest1 - nums[j];
      // cout << "rest2: " << rest2 << endl;

      int lh = j + 1;
      int rh = nums.size() - 1;
      while(lh < rh) {
        // cout << "nums[lh]: " << nums[lh] << endl;
        // cout << "nums[rh]: " << nums[rh] << endl;
        if (nums[lh] + nums[rh] == rest2) {
          // cout << nums[i] << " " << nums[j] << " " << nums[lh] << " " << nums[rh] << endl;
          vector<int> item;
          item.push_back(nums[i]);
          item.push_back(nums[j]);
          item.push_back(nums[lh]);
          item.push_back(nums[rh]);
          sort(item.begin(), item.end());
          res.push_back(item);

          lh++;
          rh--;
        } else if (nums[lh] + nums[rh] < rest2) {
          lh++;
        } else {
          rh--;
        }
      }
    }
  }

  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  return res;
}

int main() {
  int target = 0;
  int numsa[] = {1, 0, -1, 0, -2, 2};
  vector<int> nums(numsa, numsa + 6);

  vector<vector<int> > res = fourSum(nums, target);
  for (vector<int> item : res) {
    for (int elem : item) {
      cout << elem << " ";
    }
    cout << endl;
  }

  return 0;
}
