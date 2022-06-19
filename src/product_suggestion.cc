
#include "utility.hpp"

using namespace std;

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    vector<vector<string>> res;
    sort(products.begin(), products.end());

    string baseStr;

    auto right = products.begin();
    const auto left = products.end();
    for (char c : searchWord) {
      baseStr += c;
      vector<string> suggestion;
      right = lower_bound(right, left, baseStr);

      for (int i = 0; i < 3 && right + 1 != left; ++i) {
        string &s = *(right + i);
        if (s.find(baseStr)) {
          break;
        }
        suggestion.push_back(s);
      }
      res.push_back(suggestion);
    }

    return res;
  }
};

int main(int argc, char *argv[]) {

  string line;
  Solution sol;

  while (getline(cin, line)) {
    auto products = stringToVectorOf<string>(line);
    getline(cin, line);
    string word = line;

    auto ret = sol.suggestedProducts(products, word);
    string retStr = stringVector2DToString(ret);
    cout << retStr << endl;
  }

  return 0;
}