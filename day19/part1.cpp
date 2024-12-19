#include <bits/stdc++.h>
using namespace std;

bool canMakeDesign(string design, const vector<string> &patterns,
                   unordered_map<string, bool> &memo) {
  if (design.empty())
    return true;
  if (memo.count(design))
    return memo[design];

  for (const string &pattern : patterns) {
    if (design.size() >= pattern.size() &&
        design.substr(0, pattern.size()) == pattern) {
      if (canMakeDesign(design.substr(pattern.size()), patterns, memo)) {
        memo[design] = true;
        return true;
      }
    }
  }

  memo[design] = false;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string input, line;
  while (getline(cin, line))
    input += line + "\n";

  size_t split = input.find("\n\n");
  string patternsStr = input.substr(0, split);
  string designsStr = input.substr(split + 2);

  vector<string> patterns;
  stringstream ss(patternsStr);
  string pattern;
  while (getline(ss, pattern, ',')) {
    patterns.push_back(pattern.substr(pattern.find_first_not_of(" ")));
  }

  vector<string> designs;
  stringstream ds(designsStr);
  string design;
  while (getline(ds, design)) {
    if (!design.empty())
      designs.push_back(design);
  }

  int possibleCount = 0;
  unordered_map<string, bool> memo;

  for (const string &design : designs) {
    if (canMakeDesign(design, patterns, memo))
      possibleCount++;
  }

  cout << possibleCount << "\n";

  return 0;
}