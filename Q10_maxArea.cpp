#include <iostream>
#include <vector>
using namespace std;

int maxArea1(vector<int>& height) {
  int maxArea = 0, area = 0;
  for (int i = 0; i < height.size(); ++i) {
    for (int j = i + 1; j < height.size(); ++j) {
      area = (j - i) * min(height[i], height[j]);
      if (maxArea < area) {
        maxArea = area;
      }
    }
  }
  return maxArea;
}

int maxArea(vector<int>& height) {
  int maxArea = 0, area = 0;
  int i = 0, j = height.size() - 1;
  while (i < j) {
    area = (j - i) * min(height[i], height[j]);
    if (maxArea < area) {
      maxArea = area;
    }

    if (height[i] < height[j]) {
      ++i;
    } else {
      --j;
    }
  }
  return maxArea;
}

int main() {
  int a[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> height(a, a+9);
  // int x;
  // while (cin >> x) {
  //   height.push_back(x);
  // }

  int res = maxArea(height);
  cout << res << endl;
  return 0;
}
