#include "utility.hpp"
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    constexpr int numCharacter = 26;
    vector<int> res;
    if (p.length() > s.length())
      return res;
    vector<int> sFreq(numCharacter), pFreq(numCharacter);

    for (int i = 0; i < p.length(); ++i) {
      ++pFreq[p.at(i) - 'a']; // fixed
      ++sFreq[s.at(i) - 'a'];
    }
    if (sFreq == pFreq)
      res.emplace_back(0);

    for (int windowRight = p.length(); windowRight < s.length();
         ++windowRight) {
      // move the window
      int windowLeft = windowRight - p.size();
      ++sFreq[s.at(windowRight) - 'a'];
      --sFreq[s.at(windowLeft) - 'a'];

      if (sFreq == pFreq)
        res.emplace_back(windowLeft + 1);
    }
    return res;
  }
};

int main() {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    string s = line;
    getline(cin, line);
    string p = line;

    auto ret = sol.findAnagrams(s, p);

    cout << integerVectorToString(ret) << endl;
  }
  return 0;
}