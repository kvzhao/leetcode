#include "utility.hpp"
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int maxCount = 0, maxLength = 0;
    int charFreq[26] = {0};
    const int length = s.length();

    int start = 0;
    for (int end = 0; end < length; ++end) {
      maxCount = max(maxCount, ++charFreq[s.at(end) - 'A']);
      // do replacement operation
      while (end - start + 1 > k + maxCount) {
        --charFreq[s.at(start) - 'A'];
        ++start;
      }
      maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
};

int main() {
  Solution sol;
  string line;

  while (getline(cin, line)) {
    string s = line;
    getline(cin, line);
    int k = stoi(line);
    cout << sol.characterReplacement(s, k) << endl;
  }
}