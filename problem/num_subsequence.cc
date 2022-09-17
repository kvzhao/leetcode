#include "utility.hpp"
using namespace std;

class Solution {
public:
  int numMatchingSubseq(string s, vector<string> &words) {
    // TIMEOUT SOLUTION
    int count = 0;

    for (const auto &word : words) {

      int j = 0;
      for (int i = 0; i < s.length() && j < word.length(); ++i) {
        if (word[j] == s[i]) {
          ++j;
        }
      }
      if (j == word.length())
        ++count;
    }

    return count;
  }
};

int main() {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto s = line;
    getline(cin, line);
    auto words = stringToStringVector(line);
    auto ret = sol.numMatchingSubseq(s, words);
    cout << ret << endl;
  }

  return 0;
}