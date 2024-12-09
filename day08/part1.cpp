#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> grid;
  string line;
  while (getline(cin, line)) {
    if (!line.empty()) {
      grid.push_back(line);
    }
  }

  int H = grid.size();
  int W = grid[0].size();

  map<char, vector<pair<int, int>>> freq_pos;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] != '.') {
        freq_pos[grid[i][j]].push_back({j, i});
      }
    }
  }

  set<pair<int, int>> antinodes;

  for (const auto &[freq, positions] : freq_pos) {
    for (size_t i = 0; i < positions.size(); i++) {
      for (size_t j = i + 1; j < positions.size(); j++) {
        int x1 = positions[i].first, y1 = positions[i].second;
        int x2 = positions[j].first, y2 = positions[j].second;

        int dx = x2 - x1;
        int dy = y2 - y1;

        vector<pair<int, int>> potential_nodes;

        int mid_x = x1 + dx / 2;
        int mid_y = y1 + dy / 2;
        if (dx % 2 == 0 && dy % 2 == 0) {
          potential_nodes.push_back({mid_x, mid_y});
        }

        int double_x1 = x2 + dx;
        int double_y1 = y2 + dy;
        int double_x2 = x1 - dx;
        int double_y2 = y1 - dy;

        potential_nodes.push_back({double_x1, double_y1});
        potential_nodes.push_back({double_x2, double_y2});

        for (const auto &[x, y] : potential_nodes) {
          if (x >= 0 && x < W && y >= 0 && y < H) {
            antinodes.insert({x, y});
          }
        }
      }
    }
  }

  cout << antinodes.size() << '\n';

  return 0;
}