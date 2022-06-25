#include "utility.hpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
private:
  vector<vector<int>> levels;

  void travel(TreeNode *node, int level) {

    if (level == levels.size())
      levels.emplace_back(vector<int>{});

    levels.at(level).emplace_back(node->val);

    if (node->left)
      travel(node->left, level + 1);
    if (node->right)
      travel(node->right, level + 1);

    return;
  }

public:
  vector<vector<int>> levelOrder(TreeNode *root) {

    if (root == nullptr)
      return levels;
    travel(root, 0);

    return levels;
  }

  void finalize() { levels.clear(); }
};

int main() {

  Solution sol;
  string line;

  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    auto ret = sol.levelOrder(root);

    cout << integerVector2DToString(ret) << endl;

    sol.finalize();
  }
  return 0;
}