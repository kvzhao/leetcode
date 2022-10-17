#include "utility.hpp"
using namespace std;

class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> prefix(nums.size(), 0);
    prefix[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
      prefix[i] = prefix[i - 1] + nums[i];
    return prefix;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    auto rets = sol.runningSum(nums);
    cout << integerVectorToString(rets) << endl;
  }

  return 0;
}