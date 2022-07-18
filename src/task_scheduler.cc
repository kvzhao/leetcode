#include "utility.hpp"
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int taskFreq[26] = {0};

    for (char t : tasks) {
      ++taskFreq[t - 'A'];
    }

    int maxFreq = 0;
    for (int freq : taskFreq) {
      maxFreq = max(freq, maxFreq);
    }

    int numFreqTask = 0;
    for (int freq : taskFreq) {
      if (freq == maxFreq)
        ++numFreqTask;
    }

    int availableTask = (maxFreq - 1) * (n + 1) + numFreqTask;

    return max((int)tasks.size(), availableTask);
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {

    auto ts = stringToStringVector(line);
    vector<char> tasks(ts.size());
    for (size_t i = 0; i < ts.size(); ++i) {
      tasks[i] = *ts[i].c_str();
    }

    getline(cin, line);
    int n = stoi(line);

    cout << sol.leastInterval(tasks, n) << endl;
  }

  return 0;
}