#include "utility.hpp"
using namespace std;

class Solution {
  void DFS(vector<vector<int>> &image, int i, int j, int srcColor,
           int newColor) {

    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
        image[i][j] != srcColor || image[i][j] == newColor) {
      return;
    }

    image[i][j] = newColor;

    DFS(image, i + 1, j, srcColor, newColor);
    DFS(image, i - 1, j, srcColor, newColor);
    DFS(image, i, j + 1, srcColor, newColor);
    DFS(image, i, j - 1, srcColor, newColor);
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {

    int color = image[sr][sc];
    DFS(image, sr, sc, color, newColor);
    return image;
  }
};

int main() {

  string line;
  Solution sol;

  while (getline(cin, line)) {

    auto img = stringToIntegerVector2D(line);
    getline(cin, line);
    int nRow = stoi(line);
    getline(cin, line);
    int nCol = stoi(line);
    getline(cin, line);
    int color = stoi(line);

    auto ret = sol.floodFill(img, nRow, nCol, color);

    cout << integerVector2DToString(ret) << endl;
  }

  return 0;
}