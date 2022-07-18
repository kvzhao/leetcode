#include "utility.hpp"
using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {

    unordered_map<int, vector<int>> busTable;
    for (int i = 0; i < routes.size(); ++i) {
      for (int j : routes[i]) {
        busTable[j].emplace_back(i);
      }
    }

    unordered_set<int> seen{source};
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(source, 0));

    while (!bfs.empty()) {
      int stop = bfs.front().first;
      int depth = bfs.front().second;
      bfs.pop();

      if (stop == target)
        return depth;

      for (int busId : busTable[stop]) {
        for (int r : routes[busId]) {
          if (!seen.count(r)) {
            seen.insert(r);
            bfs.push(make_pair(r, depth + 1));
          }
        }
        routes[busId].clear();
      }
    }

    return -1;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto routes = stringToIntegerVector2D(line);
    getline(cin, line);
    int src = stoi(line);
    getline(cin, line);
    int dst = stoi(line);
    cout << sol.numBusesToDestination(routes, src, dst) << endl;
  }

  return 0;
}