
#include "utility.hpp"

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> hash;

    for (char c : s) {
      hash[c] += 1;
    }

    int len = 0;
    for (auto &x : hash) {
      auto v = x.second;
      len += v / 2 * 2;

      if (len % 2 == 0 && v % 2 == 1) {
        ++len;
      }
    }

    return len;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    int ret = sol.longestPalindrome(line);
    cout << ret << endl;
  }
  return 0;
}