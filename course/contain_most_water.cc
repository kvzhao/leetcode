#include "utility.hpp"
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1;
    int max_area = 0, area = 0;
    while (i < j) {
      int left = height[i], right = height[j];
      area = min(left, right) * (j - i);
      max_area = max(area, max_area);
      if (left > right)
        --j;
      else
        ++i;
    }
    return max_area;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto h = stringToIntegerVector(line);
    cout << sol.maxArea(h) << endl;
  }

  return 0;
}