#include "utility.hpp"
using namespace std;

class Solution {
  int digitSquareSum(int n) {
    int sum = 0, temp = 0;
    while (n) {
      temp = n % 10;
      sum += temp * temp;
      n /= 10;
    }
    return sum;
  }

public:
  bool isHappy(int n) {

    int fast = n;
    int slow = n;

    do {
      slow = digitSquareSum(slow);
      fast = digitSquareSum(fast);
      fast = digitSquareSum(fast);
    } while (fast != slow);

    return slow == 1;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {

    int n = stoi(line);
    cout << sol.isHappy(n) << endl;
  }

  return 0;
}