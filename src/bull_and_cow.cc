#include "utility.hpp"
using namespace std;

class Solution {
public:
  string getHint(string secret, string guess) {

    unordered_map<char, int> sMap;
    unordered_map<char, int> gMap;
    int A = 0, B = 0;
    const int length = secret.length();

    for (int i = 0; i < length; ++i) {
      char s = secret.at(i);
      char g = guess.at(i);

      if (s == g) {
        ++A;
      } else {
        (sMap[g] > 0) ? ++B, --sMap[g] : ++gMap[g];
        (gMap[s] > 0) ? ++B, --gMap[s] : ++sMap[s];
      }
    }

    return to_string(A) + "A" + to_string(B) + "B";
  }
};

int main() {

  Solution sol;
  string line;

  while (getline(cin, line)) {
    string secret = line;
    getline(cin, line);
    string guess = line;
    cout << sol.getHint(secret, guess) << endl;
  }

  return 0;
}