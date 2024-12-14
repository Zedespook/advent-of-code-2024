#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int WIDTH = 101;
const int HEIGHT = 103;
const int ADJACENCY_THRESHOLD = 200;

struct Robot {
  double x, y;
  int vx, vy;

  pii getPositionAtTime(int t) const {
    double newX = fmod(x + vx * t + WIDTH, WIDTH);
    double newY = fmod(y + vy * t + HEIGHT, HEIGHT);

    if (newX < 0)
      newX += WIDTH;
    if (newY < 0)
      newY += HEIGHT;

    return {static_cast<int>(round(newX)), static_cast<int>(round(newY))};
  }
};

int countHorizontalAdjacencies(const vector<Robot> &robots, int t) {
  set<pii> positions;
  for (const auto &robot : robots) {
    positions.insert(robot.getPositionAtTime(t));
  }

  int adjacencies = 0;
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH - 1; x++) {
      if (positions.count({x, y}) && positions.count({x + 1, y})) {
        adjacencies++;
      }
    }
  }
  return adjacencies;
}

void solve() {
  vector<Robot> robots;
  string line;

  while (getline(cin, line)) {
    Robot r;
    sscanf(line.c_str(), "p=%lf,%lf v=%d,%d", &r.x, &r.y, &r.vx, &r.vy);
    robots.push_back(r);
  }

  for (int t = 0; t < 10000; t++) {
    int adjacencies = countHorizontalAdjacencies(robots, t);
    if (adjacencies > ADJACENCY_THRESHOLD) {
      cout << t << endl;
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
