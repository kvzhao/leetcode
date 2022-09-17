#include "utility.hpp"
using namespace std;

// Paste Solution object here

class Solution {
private:
  bool isCommonPrefix(const vector<string> &strs, int len) {
    string prefix = strs.at(0).substr(0, len);

    for (size_t i = 1; i < strs.size(); ++i) {
      if (strs.at(i).find(prefix, 0) == string::npos)
        return false;
    }
    return true;
  }

public:
  string longestCommonPrefixBinarySearch(vector<string> &strs) {
    if (strs.empty())
      return "";

    if (strs.size() == 1)
      return strs[0];

    int minLength = 1e6;
    for (const auto &s : strs) {
      minLength = min(minLength, (int)s.length());
    }

    int low = 1, high = minLength;

    while (low < high) {
      int mid = low + (high - low) / 2;
      if (isCommonPrefix(strs, mid)) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return strs[0].substr(0, (low + high) / 2);
  }

  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";

    if (strs.size() == 1)
      return strs[0];

    sort(strs.begin(), strs.end());

    size_t n = strs.size();
    string start = strs[0];
    string end = strs[n - 1];

    string ans = "";
    for (size_t i = 0; i < start.length(); ++i) {
      if (start[i] == end[i])
        ans += start[i];
      else
        break;
    }

    return ans;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {

    auto strs = stringToStringVector(line);

    cout << sol.longestCommonPrefix(strs) << endl;
  }

  return 0;
}