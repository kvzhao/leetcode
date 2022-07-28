#include "utility.hpp"
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;

    int counter[26] = {0};

    for (uint32_t i = 0; i < s.length(); ++i) {
      ++counter[s[i] - 'a'];
      --counter[t[i] - 'a'];
    }

    for (uint32_t i = 0; i < 26; ++i) {
      if (counter[i] != 0)
        return false;
    }
    return true;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    string s = line;
    getline(cin, line);
    string t = line;

    cout << sol.isAnagram(s, t) << endl;
  }

  return 0;
}