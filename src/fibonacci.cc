
#include "utility.hpp"
using namespace std;

class Solution {
public:
  /*
    F(0) = 0, F(1) = 1
    F(n) = F(n - 1) + F(n - 2), for n > 1.
  */
  int fib(int n) {

    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};

int main() {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    int n = stoi(line);
    cout << sol.fib(n) << endl;
  }

  return 0;
}