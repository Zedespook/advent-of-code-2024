#include <bits/stdc++.h>
using namespace std;

bool hasPath(const vector<vector<bool>> &grid) {
  const int N = grid.size();
  vector<vector<bool>> vis(N, vector<bool>(N));
  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = true;

  const int dx[] = {0, 0, 1, -1};
  const int dy[] = {1, -1, 0, 0};

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    if (y == N - 1 && x == N - 1)
      return true;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny >= 0 && ny < N && nx >= 0 && nx < N && !grid[ny][nx] &&
          !vis[ny][nx]) {
        vis[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
  return false;
}

int main() {
  freopen("day18/input.txt", "r", stdin);

  vector<pair<int, int>> bytes;
  int x, y;
  char comma;
  while (cin >> x >> comma >> y) {
    bytes.emplace_back(x, y);
  }

  const int N = 71;
  vector<vector<bool>> grid(N, vector<bool>(N));

  for (size_t i = 0; i < bytes.size(); i++) {
    grid[bytes[i].second][bytes[i].first] = true;
    if (!hasPath(grid)) {
      cout << bytes[i].first << "," << bytes[i].second << endl;
      break;
    }
  }

  return 0;
}