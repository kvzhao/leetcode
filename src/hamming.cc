#include "utility.hpp"
using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int bitSum = 0;

    while (n != 0) {
      ++bitSum;
      n &= (n - 1);
    }

    return bitSum;
  }
};

int main() {
  Solution sol;

  return 0;
}