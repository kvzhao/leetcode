#include "utility.hpp"
using namespace std;

int findLength(vector<int> &nums, int k) {

  int left = 0, curr = 0, ans = 0;
  for (int right = 0; right < nums.size(); ++right) {
    curr += nums[right];

    while (curr > k) {
      curr -= nums[left];
      ++left;
    }

    ans = max(ans, right - left + 1);
  }
  return ans;
};

int findLengthBitString(string s) {
  int ans = 0;
  int left = 0, numFlip = 0;

  for (int right = 0; right < s.length(); ++right) {

    char b = s[right];

    if (b == '0')
      ++numFlip;

    while (numFlip > 1) {
      if (s[left] == '0') {
        --numFlip;
      }
      ++left;
    }

    ans = max(ans, right - left + 1);
  }

  return ans;
}
