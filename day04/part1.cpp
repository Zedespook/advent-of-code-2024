#include <bits/stdc++.h>
using namespace std;

constexpr array<pair<int, int>, 8> directions = {
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

bool check_xmas(const vector<string> &grid, int row, int col, int drow,
                int dcol) {
  string_view pattern = "XMAS";
  const auto rows = static_cast<int>(grid.size());
  const auto cols = static_cast<int>(grid[0].size());

  for (int i = 0; i < 4; ++i) {
    int new_row = row + i * drow;
    int new_col = col + i * dcol;
    if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols ||
        grid[new_row][new_col] != pattern[i]) {
      return false;
    }
  }
  return true;
}

int solve(const vector<string> &grid) {
  int count = 0;
  int rows = grid.size();
  int cols = grid[0].size();

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (grid[row][col] == 'X') {
        for (const auto &[drow, dcol] : directions) {
          if (check_xmas(grid, row, col, drow, dcol)) {
            ++count;
          }
        }
      }
    }
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  vector<string> grid;

  while (getline(cin, line)) {
    if (!line.empty()) {
      grid.push_back(line);
    }
  }

  cout << solve(grid) << '\n';

  return 0;
}