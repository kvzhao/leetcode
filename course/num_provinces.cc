#include "utility.hpp"
using namespace std;

class Solution {
private:
  unordered_map<int, vector<int>> graph;
  unordered_set<int> seen;

  void dfs(int node) {
    stack<int> stack;
    stack.push(node);

    while (!stack.empty()) {
      int node = stack.top();
      stack.pop();

      for (int neighbor : graph[node]) {
        if (!seen.count(neighbor)) {
          seen.insert(neighbor);
          dfs(neighbor);
        }
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    const int n = isConnected.size();
    // build graph
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isConnected[i][j] == 1) {
          graph[i].emplace_back(j);
          graph[j].emplace_back(i);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!seen.count(i)) {
        ++ans;
        seen.insert(i);
        dfs(i);
      }
    }

    return ans;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto connected = stringToIntegerVector2D(line);
    cout << sol.findCircleNum(connected) << endl;
  }

  return 0;
}