#include "utility.hpp"

using namespace std;
class Solution {
public:
  bool isIsomorphic(string s, string t) {

    if (s.length() != t.length())
      return false;

    int m1[256] = {0}, m2[256] = {0};
    int n = s.length();

    for (int i = 0; i < n; ++i) {

      if (m1[s[i]] != m2[t[i]])
        return false;

      // position of last-time
      m1[s[i]] = i + 1;
      m2[t[i]] = i + 1;
    }

    return true;
  }
};

int main(int argc, char *argv[]) {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto s = line;
    getline(cin, line);
    auto t = line;
    auto ret = sol.isIsomorphic(s, t);
    cout << ret << endl;
  }

  return 0;
}