
#include "utility.hpp"

void dfs(TreeNode *node) {
  if (node == nullptr) {
    return;
  }

  dfs(node->left);
  dfs(node->right);
}