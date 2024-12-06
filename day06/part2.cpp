#include <bits/stdc++.h>
using namespace std;

bool simulate_with_obstacle(const vector<string> &orig_grid,
                            pair<int, int> start_pos,
                            pair<int, int> obstacle_pos) {
  vector<string> grid = orig_grid;
  grid[obstacle_pos.second][obstacle_pos.first] = '#';

  pair<int, int> pos = start_pos;
  int dir = 0;
  const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  set<tuple<int, int, int>> visited;

  while (true) {
    auto state = make_tuple(pos.first, pos.second, dir);
    if (visited.count(state))
      return true;
    visited.insert(state);

    int ny = pos.second + dirs[dir].first;
    int nx = pos.first + dirs[dir].second;

    if (ny < 0 || ny >= (int)grid.size() || nx < 0 ||
        nx >= (int)grid[0].size()) {
      return false;
    }

    if (grid[ny][nx] == '#') {
      dir = (dir + 1) % 4;
    } else {
      pos = {nx, ny};
    }

    if (visited.size() > 10000)
      return true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> grid;
  string line;
  while (getline(cin, line)) {
    grid.push_back(line);
  }

  pair<int, int> start_pos;
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == '^') {
        start_pos = {j, i};
        break;
      }
    }
  }

  int loop_positions = 0;
  for (size_t y = 0; y < grid.size(); y++) {
    for (size_t x = 0; x < grid[0].size(); x++) {
      if (grid[y][x] == '#' ||
          (x == (size_t)start_pos.first && y == (size_t)start_pos.second)) {
        continue;
      }
      if (simulate_with_obstacle(grid, start_pos, {x, y})) {
        loop_positions++;
      }
    }
  }

  cout << loop_positions << endl;

  return 0;
}