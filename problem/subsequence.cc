
#include "utility.hpp"

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int j = 0;

    for (int i = 0; i < t.length() && j < s.length(); ++i) {
      if (s[j] == t[i])
        ++j;
    }

    return (j == s.length());
  }
};

int main() {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto s = line;
    getline(cin, line);
    auto t = line;
    auto ret = sol.isSubsequence(s, t);
    cout << ret << endl;
  }

  return 0;
}