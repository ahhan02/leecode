#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }

  int left = minDepth(root->left);
  int right = minDepth(root->right);

  int depth = min(left, right);
  cout << "left: " << left << " right: " << right << " depth: " << depth << endl;

  // return depth == 0 ? max(left, right) + 1 : depth + 1;
  return left && right ? min(left, right) + 1 : left + right + 1;
}

int main() {
  TreeNode* tn = new TreeNode(3);
  TreeNode* root = tn;

  tn->left = new TreeNode(9);
  tn->right = new TreeNode(20);

  tn = tn->right;
  tn->left = new TreeNode(15);
  tn->right = new TreeNode(7);

  cout << minDepth(root) << endl;
  return 0;
}
