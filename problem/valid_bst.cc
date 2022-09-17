
#include "utility.hpp"
using namespace std;

class Solution {
private:
  bool validate(TreeNode *node, TreeNode *low, TreeNode *high) {

    if (node == nullptr)
      return true;

    if ((low && node->val <= low->val) || (high && node->val >= high->val))
      return false;

    return validate(node->right, node, high) && validate(node->left, low, node);
  }

public:
  bool isValidBST(TreeNode *root) { return validate(root, nullptr, nullptr); }
};

int main() {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    bool ret = sol.isValidBST(root);
    cout << ret << endl;
  }

  return 0;
}