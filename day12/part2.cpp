#include <bits/stdc++.h>
using namespace std;

struct Position {
  int x, y;

  bool operator<(const Position &other) const {
    return tie(x, y) < tie(other.x, other.y);
  }

  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;
  }
};

struct Region {
  char type;
  set<Position> plots;
};

using Grid = vector<vector<char>>;

bool checkNeighbor(const Grid &g, Position p, int dx, int dy, char t) {
  int nx = p.x + dx, ny = p.y + dy;
  return nx >= 0 && static_cast<size_t>(nx) < g.size() && ny >= 0 &&
         static_cast<size_t>(ny) < g[0].size() && g[nx][ny] == t;
}

int countBoundaries(const Region &r, const Grid &g) {
  int h = 0, v = 0;
  auto scan = [](bool match, bool &seen, auto inc) {
    if (!match) {
      if (!seen)
        inc();
      return true;
    }
    return false;
  };

  for (size_t i = 0; i < g.size(); i++) {
    bool up = false, down = false;
    for (size_t j = 0; j < g[0].size(); j++) {
      Position p{static_cast<int>(i), static_cast<int>(j)};
      if (!r.plots.count(p)) {
        up = down = false;
        continue;
      }
      up = scan(checkNeighbor(g, p, -1, 0, r.type), up, [&] { h++; });
      down = scan(checkNeighbor(g, p, 1, 0, r.type), down, [&] { h++; });
    }
  }

  for (size_t j = 0; j < g[0].size(); j++) {
    bool left = false, right = false;
    for (size_t i = 0; i < g.size(); i++) {
      Position p{static_cast<int>(i), static_cast<int>(j)};
      if (!r.plots.count(p)) {
        left = right = false;
        continue;
      }
      left = scan(checkNeighbor(g, p, 0, -1, r.type), left, [&] { v++; });
      right = scan(checkNeighbor(g, p, 0, 1, r.type), right, [&] { v++; });
    }
  }
  return h + v;
}

set<Position> floodFill(Position start, const Grid &g) {
  const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
  set<Position> filled;
  queue<Position> q;
  q.push(start);
  filled.insert(start);
  char type = g[start.x][start.y];

  while (!q.empty()) {
    Position p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      Position next{p.x + dx[i], p.y + dy[i]};
      if (next.x >= 0 && static_cast<size_t>(next.x) < g.size() &&
          next.y >= 0 && static_cast<size_t>(next.y) < g[0].size() &&
          g[next.x][next.y] == type && !filled.count(next)) {
        filled.insert(next);
        q.push(next);
      }
    }
  }
  return filled;
}

vector<Region> findRegions(const Grid &g) {
  vector<Region> regions;
  vector<vector<bool>> seen(g.size(), vector<bool>(g[0].size()));

  for (size_t i = 0; i < g.size(); i++) {
    for (size_t j = 0; j < g[0].size(); j++) {
      if (!seen[i][j]) {
        auto connected =
            floodFill({static_cast<int>(i), static_cast<int>(j)}, g);
        for (const auto &p : connected)
          seen[p.x][p.y] = true;
        regions.push_back({g[i][j], connected});
      }
    }
  }
  return regions;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> lines;
  string line;
  while (getline(cin, line) && !line.empty())
    lines.push_back(line);

  Grid grid(lines.size(), vector<char>(lines[0].size()));
  for (size_t i = 0; i < lines.size(); i++)
    for (size_t j = 0; j < lines[i].size(); j++)
      grid[i][j] = lines[i][j];

  long long total = 0;
  for (const auto &region : findRegions(grid))
    total += (long long)region.plots.size() * countBoundaries(region, grid);

  cout << total << '\n';
  return 0;
}