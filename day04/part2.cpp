#include <bits/stdc++.h>
using namespace std;

struct Point {
  int row, col;
  Point operator+(const Point &other) const {
    return {row + other.row, col + other.col};
  }
};

bool check_mas(const vector<string> &grid, Point start, Point dir,
               bool reverse) {
  string_view pattern = reverse ? "SAM" : "MAS";
  for (int i = 0; i < 3; ++i) {
    Point pos = start + Point{dir.row * i, dir.col * i};
    if (pos.row < 0 || pos.row >= grid.size() || pos.col < 0 ||
        pos.col >= grid[0].size() || grid[pos.row][pos.col] != pattern[i]) {
      return false;
    }
  }
  return true;
}

int solve(const vector<string> &grid) {
  int count = 0;
  array<Point, 2> directions = {Point{-1, -1}, Point{-1, 1}};

  int rows = grid.size();
  int cols = grid[0].size();

  for (int row = 1; row < rows - 1; ++row) {
    for (int col = 1; col < cols - 1; ++col) {
      if (grid[row][col] != 'A')
        continue;

      Point center{row, col};

      for (const auto &dir1 : directions) {
        Point dir2{-dir1.row, dir1.col};

        for (int rev1 = 0; rev1 <= 1; ++rev1) {
          for (int rev2 = 0; rev2 <= 1; ++rev2) {
            Point start1 = center + Point{-dir1.row, -dir1.col};
            Point start2 = center + Point{-dir2.row, -dir2.col};

            if (check_mas(grid, start1, dir1, rev1) &&
                check_mas(grid, start2, dir2, rev2)) {
              ++count;
              goto next_pattern;
            }
          }
        }
      }
    next_pattern:;
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