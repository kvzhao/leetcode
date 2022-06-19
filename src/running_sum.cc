
#include "utility.hpp"

using namespace std;

class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
      nums[i] += nums[i - 1];
    }

    return nums;
  }
};

int main(int argc, char *argv[]) {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    vector<int> ret = sol.runningSum(nums);
    auto retStr = integerVectorToString(ret);
    cout << retStr << endl;
  }

  return 0;
}