
#include "utility.hpp"
using namespace std;

class Solution {
  // DFS Recursive Implementation
  void FloodFill(vector<vector<char>> &grid, int i, int j) {

    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == '0')
      return;

    grid[i][j] = '0';

    FloodFill(grid, i + 1, j);
    FloodFill(grid, i - 1, j);
    FloodFill(grid, i, j + 1);
    FloodFill(grid, i, j - 1);
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int numOfIslands = 0;
    const int gridSizeH = grid.size();
    const int gridSizeW = grid.at(0).size();

    for (int i = 0; i < gridSizeH; ++i) {
      for (int j = 0; j < gridSizeW; ++j) {
        if (grid[i][j] == '1') {
          FloodFill(grid, i, j);
          ++numOfIslands;
        }
      }
    }

    return numOfIslands;
  }
};

int main() {

  Solution sol;
  string line;
  while (getline(cin, line)) {
    auto igrid = stringToIntegerVector2D(line);
    vector<vector<char>> grid(igrid.size());
    for (int i = 0; i < igrid.size(); ++i) {
      grid[i] = vector<char>(igrid[i].size());
      for (int j = 0; j < igrid[i].size(); ++j) {
        grid[i][j] = *std::to_string(igrid[i][j]).c_str();
      }
    }
    cout << sol.numIslands(grid) << endl;
  }
}