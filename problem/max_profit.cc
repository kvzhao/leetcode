#include "utility.hpp"

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {

    int maxReturn = -1e6;
    int lowestPrice = 1e6;

    for (int price : prices) {
      lowestPrice = min(lowestPrice, price);

      auto profit = price - lowestPrice;
      maxReturn = max(maxReturn, profit);
    }

    return maxReturn;
  }
};

int main() {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    int ret = sol.maxProfit(nums);
    cout << ret << endl;
  }

  return 0;
}