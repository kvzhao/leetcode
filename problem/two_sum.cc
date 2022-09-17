
#include "utility.hpp"
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;

    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); ++i) {
      int numToFind = target - nums[i];

      if (hash.find(numToFind) != hash.end()) {
        res.emplace_back(hash[numToFind]);
        res.emplace_back(i);
        return res;
      }

      hash[nums[i]] = i;
    }

    return res;
  }
};

int main() {

  Solution sol;
  string line;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    getline(cin, line);
    int target = stoi(line);
    auto ret = sol.twoSum(nums, target);
    cout << integerVectorToString(ret) << endl;
  }

  return 0;
}