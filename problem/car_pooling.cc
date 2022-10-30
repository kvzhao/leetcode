#include "utility.hpp"
using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {}
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto trips = stringToIntegerVector2D(line);
    getline(cin, line);
    int c = stoi(line);
    cout << sol.carPooling(trips, c) << endl;
  }

  return 0;
}