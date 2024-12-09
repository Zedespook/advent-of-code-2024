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
    if (positions.size() < 2)
      continue;

    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        for (size_t i = 0; i < positions.size(); i++) {
          for (size_t j = i + 1; j < positions.size(); j++) {
            int x1 = positions[i].first, y1 = positions[i].second;
            int x2 = positions[j].first, y2 = positions[j].second;

            long long cross = (long long)(x2 - x1) * (y - y1) -
                              (long long)(y2 - y1) * (x - x1);

            if (cross == 0) {
              antinodes.insert({x, y});
              goto next_point;
            }
          }
        }
      next_point:;
      }
    }
  }

  cout << antinodes.size() << '\n';

  return 0;
}