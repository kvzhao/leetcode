
#include "utility.hpp"

using namespace std;

class Solution {
public:
  int mySqrt(int x) {

    int left = 1, right = x;

    while (left < right) {
      int mid = left + (right - left) / 2;

      // prevent overflow
      if (mid <= x / mid) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left - 1;
  }
};

int main() {

  Solution sol;
  string line;

  while (getline(cin, line)) {
    int x = stoi(line);
    cout << sol.mySqrt(x) << endl;
  }

  return 0;
}