#include "utility.hpp"
using namespace std;

class Solution {
public:
  int minimumAverageDifference(vector<int> &nums) {
    const int n = nums.size();
    int minAvgDiff = INT_MAX;
    int index = 0;
    long left = 0, right = 0;
    for (auto _n : nums)
      right += _n;

    for (int i = 0; i < n; ++i) {
      left += nums[i];
      right -= nums[i];

      int a = left / (i + 1);
      int b = (i == n - 1) ? 0 : right / (n - i - 1);
      if (abs(a - b) < minAvgDiff) {
        minAvgDiff = abs(a - b);
        index = i;
      }
    }

    return index;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    cout << sol.minimumAverageDifference(nums) << endl;
  }

  return 0;
}