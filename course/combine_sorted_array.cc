#include "utility.hpp"
using namespace std;

// Paste Solution object here
class Solution {
public:
  vector<int> combine(vector<int> v1, vector<int> v2) {
    uint32_t p1 = 0, p2 = 0;
    vector<int> c;
    while (p1 < v1.size() && p2 < v2.size()) {
      if (v1[p1] < v2[p2])
        c.emplace_back(v1[p1++]);
      else
        c.emplace_back(v2[p2++]);
    }

    while (p1 < v1.size())
      c.emplace_back(v1[p1++]);

    while (p2 < v2.size())
      c.emplace_back(v2[p2++]);

    return c;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto v1 = stringToIntegerVector(line);
    getline(cin, line);
    auto v2 = stringToIntegerVector(line);
    cout << integerVectorToString(sol.combine(v1, v2)) << endl;
  }

  return 0;
}