#include "utility.hpp"
using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int left = 0, ans = 0;
    int prod = 1;

    for (int right = 0; right < nums.size(); ++right) {

      prod *= nums[right];

      while (left <= right && prod >= k) {
        prod /= nums[left++];
      }

      ans += right - left + 1;
    }

    return ans;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);
    getline(cin, line);
    int k = stoi(line);
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
  }

  return 0;
}