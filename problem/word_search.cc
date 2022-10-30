#include "utility.hpp"
using namespace std;

class Solution {

private:
  bool backtrack(vector<vector<char>> &board, string word, int r, int c,
                 int index) {

    if (index >= word.length())
      return true;

    if (r < 0 || r >= board.size() || c < 0 || c >= board[r].size())
      return false;

    if (word.at(index) != board[r][c])
      return false;

    bool ret = false;
    board[r][c] = '#';

    const int dirRow[4] = {0, 1, 0, -1};
    const int dirCol[4] = {1, 0, -1, 0};

    for (int d = 0; d < 4; ++d) {
      ret = backtrack(board, word, r + dirRow[d], c + dirCol[d], index + 1);
      if (ret)
        break;
    }

    board[r][c] = word.at(index);

    return ret;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    if (word == "")
      return false;

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (backtrack(board, word, i, j, 0))
          return true;
      }
    }

    return false;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    vector<vector<char>> grids = stringToVector2DOf<char>(line);
    getline(cin, line);
    string word = line;
    cout << sol.exist(grids, word) << endl;
  }

  return 0;
}