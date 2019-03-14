#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    nums.insert(nums.end(), nums2.begin(), nums2.end());
    vector<int>::iterator it;
    //for (it = nums.begin(); it != nums.end(); ++it) {
    //    cout << *it << endl;
    //}


    sort(nums.begin(), nums.end());

    //for (it = nums.begin(); it != nums.end(); ++it) {
    //    cout << *it << endl;
    //}

    int len = nums.size();
    if (len % 2) {
      return nums[len/2];
    } else {
      return (nums[len/2 - 1] + nums[len/2]) / 2.;
    }
}

int main() {
    int a1[3] = {10, 8, 3};
    int a2[3] = {7, 4, 20};
    vector<int> nums1(a1, a1+3);
    vector<int> nums2(a2, a2+3);
    double res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    return 0;
}
