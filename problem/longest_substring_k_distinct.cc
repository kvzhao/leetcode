#include "utility.hpp"
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {}
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    string s = line;
    getline(cin, line);
    int k = stoi(line);
    cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;
  }

  return 0;
}