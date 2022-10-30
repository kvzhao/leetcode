#include "utility.hpp"
using namespace std;

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long ans = 0, numSubarray = 0;

    for (auto n : nums) {
      if (n == 0) {
        ++numSubarray;
      } else {
        numSubarray = 0;
      }

      ans += numSubarray;
    }

    return ans;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);
    cout << sol.zeroFilledSubarray(nums) << endl;
  }

  return 0;
}