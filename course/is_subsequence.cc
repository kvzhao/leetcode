#include "utility.hpp"
using namespace std;

// Paste Solution object here
class Solution {
public:
  bool isSubsequence(string s, string t) {
    uint32_t i = 0, j = 0;

    while (i < s.length() && j < t.length()) {
      if (s[i] == t[j])
        i++;
      j++;
    }

    return i == s.size();
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    string s = line;
    getline(cin, line);
    string t = line;

    cout << sol.isSubsequence(s, t) << endl;
  }

  return 0;
}