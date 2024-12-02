#include <bits/stdc++.h>
using namespace std;

bool isStrictlySafe(const vector<int> &levels) {
  if (levels.size() <= 1)
    return false;

  vector<int> diffs;
  for (int i = 1; i < levels.size(); i++) {
    diffs.push_back(levels[i] - levels[i - 1]);
  }

  if (any_of(diffs.begin(), diffs.end(), [](int d) { return d == 0; }))
    return false;

  if (any_of(diffs.begin(), diffs.end(), [](int d) { return abs(d) > 3; }))
    return false;

  return all_of(diffs.begin(), diffs.end(), [](int d) { return d > 0; }) ||
         all_of(diffs.begin(), diffs.end(), [](int d) { return d < 0; });
}

bool isSafe(const vector<int> &levels) {
  if (isStrictlySafe(levels))
    return true;

  for (int i = 0; i < levels.size(); i++) {
    vector<int> modified = levels;
    modified.erase(modified.begin() + i);
    if (isStrictlySafe(modified))
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  vector<vector<int>> reports;

  while (getline(cin, line)) {
    if (line.empty())
      continue;
    istringstream iss(line);
    vector<int> levels;
    int level;
    while (iss >> level) {
      levels.push_back(level);
    }
    reports.push_back(levels);
  }

  int safeCount = count_if(reports.begin(), reports.end(), isSafe);
  cout << safeCount << endl;

  return 0;
}
