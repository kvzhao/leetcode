#include "utility.hpp"
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int top = 0, left = 0, right = n - 1, bottom = m - 1;

    while (top <= bottom && left <= right) {

      for (int i = left; i <= right && top <= bottom; ++i) {
        ret.emplace_back(matrix[top][i]);
      }
      ++top;

      for (int i = top; i <= bottom && right >= left; ++i) {
        ret.emplace_back(matrix[i][right]);
      }
      --right;

      for (int i = right; i >= left && bottom >= top; --i) {
        ret.emplace_back(matrix[bottom][i]);
      }
      --bottom;

      for (int i = bottom; i >= top && left <= right; --i) {
        ret.emplace_back(matrix[i][left]);
      }
      ++left;
    }

    return ret;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto m = stringToIntegerVector2D(line);
    cout << integerVectorToString(sol.spiralOrder(m)) << endl;
  }

  return 0;
}