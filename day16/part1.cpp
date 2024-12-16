#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(), v.end()

const int INF = 1e9;
const vector<pii> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct State {
  int y, x, dir, cost;
  State(int y, int x, int dir, int cost) : y(y), x(x), dir(dir), cost(cost) {}
  bool operator>(const State &other) const { return cost > other.cost; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<string> grid;
  string line;
  while (getline(cin, line))
    grid.pb(line);

  int n = grid.size(), m = grid[0].size();
  pii start, end;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'S')
        start = {i, j};
      if (grid[i][j] == 'E')
        end = {i, j};
    }
  }

  vector<vector<vector<int>>> dist(n,
                                   vector<vector<int>>(m, vector<int>(4, INF)));
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.push(State(start.F, start.S, 1, 0));

  while (!pq.empty()) {
    auto [y, x, dir, cost] = pq.top();
    pq.pop();

    if (dist[y][x][dir] < cost)
      continue;
    if (make_pair(y, x) == end) {
      cout << cost << "\n";
      return 0;
    }

    for (int newDir = 0; newDir < 4; newDir++) {
      int rotCost = 0;
      if (dir != newDir) {
        int diff = abs(newDir - dir);
        rotCost = (diff == 3 ? 1 : diff) * 1000;
      }

      int ny = y + dirs[newDir].F;
      int nx = x + dirs[newDir].S;

      if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] != '#') {
        int newCost = cost + rotCost + 1;
        if (newCost < dist[ny][nx][newDir]) {
          dist[ny][nx][newDir] = newCost;
          pq.push(State(ny, nx, newDir, newCost));
        }
      }
    }
  }

  return 0;
}