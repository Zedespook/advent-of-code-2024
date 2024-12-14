#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int WIDTH = 101;
const int HEIGHT = 103;
const int TIME = 100;

struct Robot {
  double x, y;
  int vx, vy;

  void update() {
    x += vx;
    y += vy;

    x = fmod(x + WIDTH, WIDTH);
    y = fmod(y + HEIGHT, HEIGHT);

    if (x < 0)
      x += WIDTH;
    if (y < 0)
      y += HEIGHT;
  }

  pii getPos() const {
    return {static_cast<int>(round(x)), static_cast<int>(round(y))};
  }
};

void solve() {
  vector<Robot> robots;
  string line;

  // Parse input
  while (getline(cin, line)) {
    Robot r;
    sscanf(line.c_str(), "p=%lf,%lf v=%d,%d", &r.x, &r.y, &r.vx, &r.vy);
    robots.push_back(r);
  }

  for (int t = 0; t < TIME; t++) {
    for (auto &robot : robots) {
      robot.update();
    }
  }

  vector<int> quadrants(4, 0);
  for (const auto &robot : robots) {
    auto [x, y] = robot.getPos();

    if (x == WIDTH / 2 || y == HEIGHT / 2)
      continue;

    int quadrant = (x > WIDTH / 2 ? 1 : 0) + (y > HEIGHT / 2 ? 2 : 0);
    quadrants[quadrant]++;
  }

  ll result = 1;
  for (int count : quadrants) {
    result *= count;
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}