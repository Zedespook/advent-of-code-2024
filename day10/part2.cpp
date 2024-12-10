#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> grid;
  string line;

  while (getline(cin, line)) {
    if (line.empty())
      continue;
    grid.push_back(line);
  }

  int rows = grid.size();
  int cols = grid[0].size();

  auto isValid = [&](int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
  };

  auto countDistinctPaths = [&](int startX, int startY) {
    set<string> uniquePaths;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    function<void(int, int, int, string &)> dfs = [&](int x, int y, int height,
                                                      string &path) {
      if (!isValid(x, y) || visited[x][y])
        return;

      int currentHeight = grid[x][y] - '0';
      if (currentHeight != height)
        return;

      visited[x][y] = true;
      path += to_string(x) + "," + to_string(y) + ";";

      if (currentHeight == 9) {
        uniquePaths.insert(path);
      } else {
        for (int dir = 0; dir < 4; ++dir) {
          int newX = x + dx[dir];
          int newY = y + dy[dir];
          dfs(newX, newY, height + 1, path);
        }
      }

      path = path.substr(0, path.length() - (to_string(x).length() +
                                             to_string(y).length() + 2));
      visited[x][y] = false;
    };

    string currentPath;
    dfs(startX, startY, 0, currentPath);
    return uniquePaths.size();
  };

  long long totalRating = 0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] == '0') {
        int rating = countDistinctPaths(i, j);
        totalRating += rating;
      }
    }
  }

  cout << totalRating << '\n';
  return 0;
}