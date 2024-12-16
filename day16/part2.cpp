#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define piii pair<pii, int>
#define piiii pair<pii, pii>
#define mp make_pair
#define fi first
#define se second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

vector<string> grid;
int H, W;
pii start, end_pos;
map<piiii, int> dist;
map<piiii, vector<piiii>> previous_states;

int turn_cost(int d1, int d2) {
  if (d1 == d2)
    return 0;
  return abs(d1 - d2) == 2 ? 2000 : 1000;
}

void dijkstra() {
  priority_queue<pair<int, piiii>, vector<pair<int, piiii>>, greater<>> pq;
  pq.push({0, {{start.fi, start.se}, {0, 0}}});
  dist[{{start.fi, start.se}, {0, 0}}] = 0;

  while (!pq.empty()) {
    int cost = pq.top().fi;
    int y = pq.top().se.fi.fi;
    int x = pq.top().se.fi.se;
    int dir = pq.top().se.se.fi;
    pq.pop();

    if (cost > dist[{{y, x}, {dir, 0}}])
      continue;

    for (int new_dir = 0; new_dir < 4; new_dir++) {
      int ny = y + dy[new_dir];
      int nx = x + dx[new_dir];
      int turn = turn_cost(dir, new_dir);

      if (ny < 0 || ny >= H || nx < 0 || nx >= W || grid[ny][nx] == '#')
        continue;

      int new_cost = cost + turn + 1;
      if (!dist.count({{ny, nx}, {new_dir, 0}}) ||
          new_cost <= dist[{{ny, nx}, {new_dir, 0}}]) {
        dist[{{ny, nx}, {new_dir, 0}}] = new_cost;
        pq.push({new_cost, {{ny, nx}, {new_dir, 0}}});
        if (new_cost == dist[{{ny, nx}, {new_dir, 0}}]) {
          previous_states[{{ny, nx}, {new_dir, 0}}].push_back(
              {{y, x}, {dir, 0}});
        }
      }
    }
  }
}

set<pii> find_optimal_tiles() {
  set<pii> tiles;
  queue<piiii> q;
  set<piiii> visited;

  for (int dir = 0; dir < 4; dir++) {
    piiii end_state = {{end_pos.fi, end_pos.se}, {dir, 0}};
    if (dist.count(end_state))
      q.push(end_state);
  }

  while (!q.empty()) {
    piiii curr = q.front();
    q.pop();

    if (visited.count(curr))
      continue;
    visited.insert(curr);

    tiles.insert({curr.fi.fi, curr.fi.se});

    if (previous_states.count(curr)) {
      for (const auto &p : previous_states[curr]) {
        q.push(p);
      }
    }
  }

  return tiles;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string line;
  while (getline(cin, line)) {
    if (line.empty())
      break;
    grid.push_back(line);
  }

  H = grid.size();
  W = grid[0].size();

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == 'S')
        start = {i, j};
      if (grid[i][j] == 'E')
        end_pos = {i, j};
    }
  }

  dijkstra();
  set<pii> optimal_tiles = find_optimal_tiles();
  cout << optimal_tiles.size() << "\n";

  return 0;
}