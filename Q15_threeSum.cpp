#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<vector<int> > threeSum1(vector<int>& nums) {
  map<int, int> resToIdx;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    resToIdx[nums[i]] = i+1;
  }

  int i, j, target, rest;
  vector<vector<int> > res;
  // vector<int> item;

  for (i = 0; i < nums.size(); ++i) {
    target = -nums[i];
    // cout << "target: " << target << "\t";

    for (j = i+1; j < nums.size(); ++j) {
      rest = target - nums[j];
      // cout << "rest: " << rest << "\t";
      // cout << "resToIdx[rest]: " << resToIdx[rest] << endl;
      if (resToIdx[rest] && resToIdx[rest]-1 > j) {
        // cout << nums[i] << " " << nums[j] << " " << rest << endl;
        vector<int> item;
        item.push_back(nums[i]);
        item.push_back(nums[j]);
        item.push_back(rest);
        // sort(item.begin(), item.end());
        res.push_back(item);
      }
    }
  }

  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());

  return res;
}

vector<vector<int> > threeSum(vector<int>& nums) {
  vector<vector<int> > res;

  sort(nums.begin(), nums.end());

  int lh, rh;
  for (int i = 0; i < nums.size(); ++i) {
    lh = i + 1;
    rh = nums.size() - 1;
    while (lh < rh) {
      int tmp = nums[i] + nums[lh] + nums[rh];
      if (tmp == 0) {
        vector<int> item;
        item.push_back(nums[i]);
        item.push_back(nums[lh++]);
        item.push_back(nums[rh--]);
        res.push_back(item);

        while (lh < rh && nums[lh] == nums[lh-1]) lh++;
        while (lh < rh && nums[rh] == nums[rh+1]) rh--;
      } else if (tmp > 0) {
        rh--;
      } else {
        lh++;
      }
    }
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  return res;
}



int main() {
  int a[] = {-1, 0, 1, 2, -1, -4};
  vector<int> nums(a, a+6);
  vector<vector<int> > res = threeSum(nums);
  /*
  for (vector<int> row : res) {
    for (int col : row) {
      cout << col << " ";
    }
    cout << endl;
  }
  */

  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res[i].size(); ++j) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
