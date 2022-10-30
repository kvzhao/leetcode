#include "utility.hpp"
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      char temp = s[i];
      s[i++] = s[j];
      s[j--] = temp;
    }
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    // string to vec of char
    vector<char> vc(line.begin(), line.end());
    sol.reverseString(vc);
    // vec of char to string
    string rs(vc.begin(), vc.end());
    cout << rs << endl;
  }

  return 0;
}