#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
0 2 3
1 3 3
2 4 3
3 4 4
4 5 4
5 5 5
0 + 2 + 3 = 5

0 2 4
1 3 4
2 4 4
3 5 4
4 5 5
5 6 5
6 6 6
0 + 2 + 4 = 6

1 2 3
2 3 3
3 4 3
4 4 4
1 + 2 + 3 = 6
6 - 3 = 3 = 1 * 3

2 2 3
3 3 3
2 + 2 + 3 = 7
7 - 1 = 6 = 2 * 3
*/

int minMoves(vector<int>& nums) {
  // int minNum = *min_element(nums, nums+nums.size());
  int minNum = *min_element(nums.begin(), nums.end());
  // cout << minNum << endl;
  // int sumNum = accumulate(nums.begin(), nums.end(), 0);
  // return sumNum - minNum * nums.size();

  int sumNum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sumNum += nums[i] - minNum;
  }

  return sumNum;
}

int main() {
  int numsArray[3] = {1, 2, 3};
  vector<int> nums(numsArray, numsArray+3);
  cout << minMoves(nums) << endl;
  return 0;
}


