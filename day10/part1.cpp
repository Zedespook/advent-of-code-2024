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

  auto findReachableNines = [&](int startX, int startY) {
    set<pair<int, int>> reachableNines;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    function<void(int, int, int)> dfs = [&](int x, int y, int height) {
      if (!isValid(x, y) || visited[x][y])
        return;

      int currentHeight = grid[x][y] - '0';
      if (currentHeight != height)
        return;

      visited[x][y] = true;

      if (currentHeight == 9) {
        reachableNines.insert({x, y});
        return;
      }

      for (int dir = 0; dir < 4; ++dir) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        dfs(newX, newY, height + 1);
      }
    };

    dfs(startX, startY, 0);
    return reachableNines.size();
  };

  int totalScore = 0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] == '0') {
        int score = findReachableNines(i, j);
        totalScore += score;
      }
    }
  }

  cout << totalScore << '\n';
  return 0;
}