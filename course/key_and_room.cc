#include "utility.hpp"
using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    unordered_set<int> visited;
    deque<int> toVisit{0};
    while (!toVisit.empty()) {
      int node = toVisit.front();
      visited.emplace(node);
      toVisit.pop_front();
      for (auto r : rooms[node]) {
        if (!visited.count(r))
          toVisit.emplace_back(r);
      }
    }
    return rooms.size() == visited.size();
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto rooms = stringToIntegerVector2D(line);
    cout << sol.canVisitAllRooms(rooms) << endl;
  }

  return 0;
}