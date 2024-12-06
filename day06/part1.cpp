#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> grid;
  string line;
  while (getline(cin, line)) {
    grid.push_back(line);
  }

  pair<int, int> pos;
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == '^') {
        pos = {j, i};
        break;
      }
    }
  }

  const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int dir = 0;
  set<pair<int, int>> visited;
  visited.insert(pos);

  while (true) {
    int ny = pos.second + dirs[dir].first;
    int nx = pos.first + dirs[dir].second;

    if (ny < 0 || ny >= (int)grid.size() || nx < 0 ||
        nx >= (int)grid[0].size()) {
      break;
    }

    if (grid[ny][nx] == '#') {
      dir = (dir + 1) % 4;
    } else {
      pos = {nx, ny};
      visited.insert(pos);
    }
  }

  cout << visited.size() << endl;

  return 0;
}