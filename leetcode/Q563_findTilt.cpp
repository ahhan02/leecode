#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int tilt = 0;
int countTilt(TreeNode* root) {
  if (!root) {
    return 0;
  }

  int leftNum = countTilt(root->left);
  int rightNum = countTilt(root->right);

  tilt += abs(leftNum - rightNum);

  cout << "leftNum: " << leftNum << " rightNum: " << rightNum <<
    " tilt: " << tilt << endl;
  return leftNum + rightNum + root->val;
}

int findTilt(TreeNode* root) {
  countTilt(root);
  return tilt;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  cout << findTilt(root) << endl;
  return 0;
}



