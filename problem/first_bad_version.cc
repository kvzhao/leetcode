

#include "utility.hpp"
using namespace std;
/*
    Template
        Minimize k , s.t. condition(k) is True

    def binary_search(array) -> int:
        def condition(value) -> bool:
            pass

        left, right = 0, len(array)
        while left < right:
            mid = left + (right - left) // 2
            if condition(mid):
                right = mid
            else:
                left = mid + 1
        return left:

    * Correctly initialize the boundary variables left and right. Only one rule:
   set up the boundary to include all possible elements;
    * Decide return value. Is it return left or return left - 1? Remember this:
   after exiting the while loop, left is the minimal k​ satisfying the
   condition function;
    * Design the condition function. This is the most difficult and most
   beautiful part. Needs lots of practice.

   Reference:
    https://leetcode.com/problems/first-bad-version/discuss/769685/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
*/

int gBadVersion = 0;
// The API isBadVersion is defined for you.
bool isBadVersion(int version) { return version >= gBadVersion; };

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 1, right = n;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};

int main() {

  Solution sol;

  string line;

  while (getline(cin, line)) {
    int n = stoi(line);
    getline(cin, line);
    gBadVersion = stoi(line);

    auto ret = sol.firstBadVersion(n);

    cout << ret << endl;
  }

  return 0;
}