#include <bits/stdc++.h>
using namespace std;

bool check_valid_sequence(const vector<int> &seq,
                          const map<int, set<int>> &rules) {
  for (size_t i = 0; i < seq.size(); ++i) {
    auto it = rules.find(seq[i]);
    if (it == rules.end())
      continue;

    for (int after : it->second) {
      auto pos = find(seq.begin(), seq.end(), after);
      if (pos != seq.end() && pos - seq.begin() <= static_cast<long>(i)) {
        return false;
      }
    }
  }
  return true;
}

int solve(const vector<vector<int>> &sequences,
          const vector<pair<int, int>> &rules) {
  map<int, set<int>> rule_map;
  for (const auto &[before, after] : rules) {
    rule_map[before].insert(after);
  }

  int sum = 0;
  for (const auto &seq : sequences) {
    if (check_valid_sequence(seq, rule_map)) {
      sum += seq[seq.size() / 2];
    }
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  vector<pair<int, int>> rules;
  vector<vector<int>> sequences;
  bool parsing_rules = true;

  while (getline(cin, line)) {
    if (line.empty())
      continue;

    if (parsing_rules && line.find('|') != string::npos) {
      stringstream ss(line);
      int before, after;
      char delimiter;
      ss >> before >> delimiter >> after;
      rules.emplace_back(before, after);
    } else {
      parsing_rules = false;
      vector<int> seq;
      stringstream ss(line);
      int num;
      while (ss >> num) {
        seq.push_back(num);
        if (ss.peek() == ',')
          ss.ignore();
      }
      if (!seq.empty())
        sequences.push_back(seq);
    }
  }

  cout << solve(sequences, rules) << '\n';
  return 0;
}