#include <bits/stdc++.h>
using namespace std;

vector<int> getHeights(const vector<string> &schematic, bool isLock) {
  vector<int> heights;
  int rows = schematic.size();
  int cols = schematic[0].size();

  for (int col = 0; col < cols; col++) {
    int height = 0;
    if (isLock) {
      for (int row = 0; row < rows; row++) {
        if (schematic[row][col] == '#') {
          height = row;
        }
      }
    } else {
      for (int row = rows - 1; row >= 0; row--) {
        if (schematic[row][col] == '#') {
          height = rows - 1 - row;
        }
      }
    }
    heights.push_back(height);
  }
  return heights;
}

bool doesFit(const vector<int> &lock, const vector<int> &key) {
  for (size_t i = 0; i < lock.size(); i++) {
    if (lock[i] + key[i] >= 6) {
      return false;
    }
  }
  return true;
}

int main() {
  ifstream file("day25/input.txt");
  string line;
  vector<vector<string>> schematics;
  vector<string> current;

  while (getline(file, line)) {
    if (line.empty()) {
      if (!current.empty()) {
        schematics.push_back(current);
        current.clear();
      }
    } else {
      current.push_back(line);
    }
  }
  if (!current.empty()) {
    schematics.push_back(current);
  }

  vector<vector<int>> locks, keys;

  for (const auto &schematic : schematics) {
    if (schematic[0] == string(5, '#')) {
      locks.push_back(getHeights(schematic, true));
    } else {
      keys.push_back(getHeights(schematic, false));
    }
  }

  // Count fitting pairs
  int count = 0;
  for (const auto &lock : locks) {
    for (const auto &key : keys) {
      if (doesFit(lock, key)) {
        count++;
      }
    }
  }

  cout << count << endl;
  return 0;
}