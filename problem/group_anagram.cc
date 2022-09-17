#include "utility.hpp"
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    unordered_map<string, vector<string>> mp;

    for (const auto &s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      mp[t].emplace_back(s);
    }

    vector<vector<string>> anagrams;

    for (const auto &m : mp) {
      anagrams.emplace_back(m.second);
    }

    return anagrams;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto strs = stringToStringVector(line);

    auto rets = sol.groupAnagrams(strs);

    cout << stringVector2DToString(rets) << endl;
  }

  return 0;
}