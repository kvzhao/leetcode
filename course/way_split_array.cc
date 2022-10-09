#include "utility.hpp"
using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    int total = 0;
    for (auto n : nums)
      total += n;

    int ans = 0;
    int left = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
      left += nums[i];
      int right = total - left;

      if (left >= right)
        ++ans;
    }

    return ans;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    cout << sol.waysToSplitArray(nums) << endl;
  }

  return 0;
}