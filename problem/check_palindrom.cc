#include "utility.hpp"
using namespace std;

class Solution {
public:
  bool checkIfPalindrome(string s) {

    uint32_t left = 0, right = s.size() - 1;

    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      ++left;
      --right;
    }

    return true;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    cout << sol.checkIfPalindrome(line) << endl;
  }

  return 0;
}