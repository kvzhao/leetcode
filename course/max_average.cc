#include "utility.hpp"
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < k; ++i) {
      sum += nums[i];
    }

    ans = sum;
    for (int right = k; right < nums.size(); ++right) {
      sum += nums[right] - nums[right - k];
      ans = max(ans, sum);
    }

    return (double)ans / k;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    getline(cin, line);
    int k = stoi(line);
    cout << sol.findMaxAverage(nums, k) << endl;
  }

  return 0;
}