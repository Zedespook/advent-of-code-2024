#include <bits/stdc++.h>
using namespace std;

const auto GROWING = [](int i) { return i + 1; };
const auto SHRINKING = [](int i) { return i - 1; };

struct GameState {
  vector<vector<char>> grid;
  string moves;
  vector<vector<int>> chainedBoxes;
  int width;
  int height;
  int robotX;
  int robotY;
};

string expandLine(const string &line) {
  string result;
  for (char c : line) {
    if (c == '#') {
      result += "##";
    } else if (c == 'O') {
      result += "[]";
    } else if (c == '.') {
      result += "..";
    } else if (c == '@') {
      result += "@.";
    } else {
      throw runtime_error("Invalid character: " + string(1, c));
    }
  }
  return result;
}

GameState parseInput(const string &input) {
  GameState state;

  auto pos = input.find("\n\n");
  string gridString = input.substr(0, pos);
  state.moves = input.substr(pos + 2);
  state.moves.erase(remove(state.moves.begin(), state.moves.end(), '\n'),
                    state.moves.end());

  string expanded;
  stringstream ss(gridString);
  string line;
  while (getline(ss, line)) {
    if (!expanded.empty())
      expanded += '\n';
    expanded += expandLine(line);
  }

  stringstream expandedSs(expanded);
  while (getline(expandedSs, line)) {
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

set<int> findChainedBoxes(const GameState &state, int y) {
  const auto &prevMoves = state.chainedBoxes.back();
  set<int> nextMoves;
  for (int x : prevMoves) {
    if (state.grid[y][x] == ']') {
      nextMoves.insert(x - 1);
    }
    if (state.grid[y][x] != '.') {
      nextMoves.insert(x);
    }
    if (state.grid[y][x] == '[') {
      nextMoves.insert(x + 1);
    }
  }
  return nextMoves;
}

optional<bool> checkVerticalMove(const GameState &state, int y) {
  bool allSpaces =
      all_of(state.chainedBoxes.back().begin(), state.chainedBoxes.back().end(),
             [&](int x) { return state.grid[y][x] == '.'; });

  if (!allSpaces) {
    bool hitWall = any_of(state.chainedBoxes.back().begin(),
                          state.chainedBoxes.back().end(),
                          [&](int x) { return state.grid[y][x] == '#'; });

    if (!hitWall) {
      return nullopt;
    }
    return false;
  }
  return true;
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

bool canMoveDirection(GameState &state, const function<int(int)> &direction) {
  state.chainedBoxes.clear();
  state.chainedBoxes.push_back({state.robotX});
  int iY = direction(state.robotY);

  while (0 < iY && iY < state.height) {
    auto canMove = checkVerticalMove(state, iY);
    if (canMove.has_value()) {
      return canMove.value();
    }
    auto nextMoves = findChainedBoxes(state, iY);
    state.chainedBoxes.push_back(
        vector<int>(nextMoves.begin(), nextMoves.end()));
    iY = direction(iY);
  }
  return false;
}

void copyLines(GameState &state, const function<int(int)> &direction) {
  int iY = state.robotY;
  unordered_map<int, char> prevLine;
  unordered_map<int, char> currentLine;

  for (const auto &toMove : state.chainedBoxes) {
    currentLine.clear();
    for (int mx : toMove) {
      currentLine[mx] = state.grid[iY][mx];
      state.grid[iY][mx] = prevLine.count(mx) ? prevLine[mx] : '.';
    }
    for (const auto &[mx, ch] : prevLine) {
      state.grid[iY][mx] = ch;
    }
    prevLine = currentLine;
    iY = direction(iY);
  }
  for (const auto &[mx, ch] : prevLine) {
    state.grid[iY][mx] = ch;
  }
}

void applyMove(GameState &state, char move) {
  if (move == '^' && canMoveDirection(state, SHRINKING)) {
    copyLines(state, SHRINKING);
    --state.robotY;
  } else if (move == 'v' && canMoveDirection(state, GROWING)) {
    copyLines(state, GROWING);
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
      if (state.grid[y][x] == '[') {
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