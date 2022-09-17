#include "utility.hpp"

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {

    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target)
        return mid;

      if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }
};

int main() {

  Solution sol;
  string line;

  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    getline(cin, line);
    int tar = stoi(line);
    int ret = sol.search(nums, tar);
    cout << ret << endl;
  }

  return 0;
}