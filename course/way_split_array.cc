#include "utility.hpp"
using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    vector<int> prefix{nums};
    for (size_t i = 1; i < prefix.size(); ++i) {
      prefix[i] += prefix[i - 1];
    }

    int ans = 0;
    for (size_t i = 0; i < prefix.size() - 1; ++i) {
      int left = prefix[i];
      int right = prefix.back() - prefix[i];

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