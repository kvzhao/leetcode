#include "utility.hpp"
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
private:
  void travel(Node *node, vector<int> &results) {

    if (node == nullptr)
      return;

    for (auto *child : node->children) {
      travel(child, results);
    }

    results.emplace_back(node->val);
  }

public:
  vector<int> postorder(Node *root) {

    vector<int> res;

    travel(root, res);

    return res;
  }
};

int main() { return 0; }