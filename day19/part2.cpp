#include <bits/stdc++.h>
using namespace std;

long long countArrangements(string design, const vector<string> &patterns,
                            unordered_map<string, long long> &memo) {
  if (design.empty())
    return 1;
  if (memo.count(design))
    return memo[design];

  long long total = 0;
  for (const string &pattern : patterns) {
    if (design.size() >= pattern.size() &&
        design.substr(0, pattern.size()) == pattern) {
      total += countArrangements(design.substr(pattern.size()), patterns, memo);
    }
  }

  memo[design] = total;
  return total;
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

  long long totalArrangements = 0;
  unordered_map<string, long long> memo;

  for (const string &design : designs) {
    totalArrangements += countArrangements(design, patterns, memo);
  }

  cout << totalArrangements << "\n";

  return 0;
}