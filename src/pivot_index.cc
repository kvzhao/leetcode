
#include "utility.hpp"
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {

    int rightSum = accumulate(nums.begin(), nums.end(), 0);

    int leftSum = 0;
    for (size_t i = 0; i < nums.size(); ++i, leftSum += nums[i - 1]) {
      rightSum -= nums[i];
      if (rightSum == leftSum) {
        return i;
      }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    int ret = sol.pivotIndex(nums);
    cout << ret << endl;
  }

  return 0;
}