#include "utility.hpp"
using namespace std;

// Paste Solution object here
class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int numFlip = 0;
    int left = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); ++right) {
      if (nums[right] == 0) {
        ++numFlip;
      }

      while (numFlip > k) {
        if (nums[left] == 0) {
          --numFlip;
        }
        ++left;
      }
      ans = max(ans, right - left + 1);
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
    cout << sol.longestOnes(nums, k) << endl;
  }

  return 0;
}