#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Region {
  int area = 0;
  int perimeter = 0;
};

bool isValid(int x, int y, int rows, int cols) {
  return x >= 0 && x < rows && y >= 0 && y < cols;
}

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x,
         int y, char plant, Region &region) {
  if (!isValid(x, y, grid.size(), grid[0].size()) || visited[x][y] ||
      grid[x][y] != plant) {
    return;
  }

  visited[x][y] = true;
  region.area++;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (!isValid(nx, ny, grid.size(), grid[0].size()) ||
        grid[nx][ny] != plant) {
      region.perimeter++;
    }
  }

  for (int i = 0; i < 4; i++) {
    dfs(grid, visited, x + dx[i], y + dy[i], plant, region);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> lines;
  string line;
  while (getline(cin, line) && !line.empty()) {
    lines.push_back(line);
  }

  int rows = lines.size();
  int cols = lines[0].size();
  vector<vector<char>> grid(rows, vector<char>(cols));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = lines[i][j];
    }
  }

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  long long total_price = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!visited[i][j]) {
        Region region;
        dfs(grid, visited, i, j, grid[i][j], region);
        total_price += (long long)region.area * region.perimeter;
      }
    }
  }

  cout << total_price << '\n';
  return 0;
}