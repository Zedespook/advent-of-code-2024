#include <bits/stdc++.h>
using namespace std;

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

  for (size_t i = 0; i < min<size_t>(1024, bytes.size()); i++) {
    grid[bytes[i].second][bytes[i].first] = true;
  }

  vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 0;

  const int dx[] = {0, 0, 1, -1};
  const int dy[] = {1, -1, 0, 0};

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny >= 0 && ny < N && nx >= 0 && nx < N && !grid[ny][nx] &&
          dist[ny][nx] == INT_MAX) {
        dist[ny][nx] = dist[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }

  cout << dist[N - 1][N - 1] << endl;
  return 0;
}