
#include "utility.hpp"
using namespace std;
vector<bool> answerQuery(vector<int> &nums, int limit,
                         const vector<pair<int, int>> &queries) {
  vector<bool> ans;

  vector<int> prefix{nums[0]};
  for (size_t i = 1; i < nums.size(); ++i) {
    prefix.emplace_back(prefix.back() + nums[i]);
  }

  for (const auto &p : queries) {
    int i = p.first, j = p.second;
    int curr = prefix[j] - prefix[i] + nums[i];
    ans.emplace_back(curr > limit);
  }

  return ans;
}