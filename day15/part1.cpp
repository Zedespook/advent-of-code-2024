#include <bits/stdc++.h>
using namespace std;

const auto GROWING = [](int i) { return i + 1; };
const auto SHRINKING = [](int i) { return i - 1; };

struct GameState {
  vector<vector<char>> grid;
  string moves;
  int width;
  int height;
  int robotX;
  int robotY;
};

GameState parseInput(const string &input) {
  GameState state;

  auto pos = input.find("\n\n");
  string gridString = input.substr(0, pos);
  state.moves = input.substr(pos + 2);
  state.moves.erase(remove(state.moves.begin(), state.moves.end(), '\n'),
                    state.moves.end());

  stringstream ss(gridString);
  string line;
  while (getline(ss, line)) {
    state.grid.push_back(vector<char>(line.begin(), line.end()));
  }
  state.height = state.grid.size();
  state.width = state.grid[0].size();

  bool found = false;
  for (int y = 0; y < state.height && !found; y++) {
    for (int x = 0; x < state.width && !found; x++) {
      if (state.grid[y][x] == '@') {
        state.robotX = x;
        state.robotY = y;
        found = true;
      }
    }
  }
  if (!found) {
    throw runtime_error("Robot not found");
  }

  return state;
}

int findFirstSpace(const GameState &state, const function<int(int)> &direction,
                   bool isHorizontal) {
  int i = isHorizontal ? state.robotX : state.robotY;
  int limit = isHorizontal ? state.width : state.height;

  while (0 < i && i < limit) {
    int x = isHorizontal ? i : state.robotX;
    int y = isHorizontal ? state.robotY : i;

    if (state.grid[y][x] == '.') {
      return i;
    } else if (state.grid[y][x] == '#') {
      return -1;
    }
    i = direction(i);
  }
  return -1;
}

void copyLine(GameState &state, const function<int(int)> &direction,
              bool isHorizontal) {
  auto copyDirection = [&direction](int x) {
    return direction(x) == x - 1 ? GROWING(x) : SHRINKING(x);
  };
  int i = findFirstSpace(state, direction, isHorizontal);
  int target = isHorizontal ? state.robotX : state.robotY;

  for (; i != target; i = copyDirection(i)) {
    int next = copyDirection(i);
    if (isHorizontal) {
      swap(state.grid[state.robotY][i], state.grid[state.robotY][next]);
    } else {
      swap(state.grid[i][state.robotX], state.grid[next][state.robotX]);
    }
  }
}

void applyMove(GameState &state, char move) {
  if (move == '^' && findFirstSpace(state, SHRINKING, false) > -1) {
    copyLine(state, SHRINKING, false);
    --state.robotY;
  } else if (move == 'v' && findFirstSpace(state, GROWING, false) > -1) {
    copyLine(state, GROWING, false);
    ++state.robotY;
  } else if (move == '<' && findFirstSpace(state, SHRINKING, true) > -1) {
    copyLine(state, SHRINKING, true);
    --state.robotX;
  } else if (move == '>' && findFirstSpace(state, GROWING, true) > -1) {
    copyLine(state, GROWING, true);
    ++state.robotX;
  }
}

long calculateScore(const GameState &state) {
  long sum = 0;
  for (int y = 0; y < state.height; y++) {
    for (int x = 0; x < state.width; x++) {
      if (state.grid[y][x] == 'O') {
        sum += (100L * y + x);
      }
    }
  }
  return sum;
}

long solve(GameState &state) {
  for (char move : state.moves) {
    applyMove(state, move);
  }
  return calculateScore(state);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string input;
  string line;
  while (getline(cin, line)) {
    input += line + '\n';
  }

  auto state = parseInput(input);
  cout << solve(state) << '\n';
  return 0;
}