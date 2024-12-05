#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort(vector<int> &nodes,
                             const map<int, set<int>> &rules) {
  map<int, vector<int>> graph;
  set<int> node_set(nodes.begin(), nodes.end());

  // Build graph for the subset of nodes
  for (int node : nodes) {
    auto it = rules.find(node);
    if (it != rules.end()) {
      for (int succ : it->second) {
        if (node_set.count(succ)) {
          graph[node].push_back(succ);
        }
      }
    }
  }

  vector<int> result;
  set<int> visited, temp;

  function<bool(int)> visit = [&](int node) {
    if (temp.count(node))
      return false;
    if (visited.count(node))
      return true;

    temp.insert(node);
    for (int succ : graph[node]) {
      if (!visit(succ))
        return false;
    }
    temp.erase(node);
    visited.insert(node);
    result.push_back(node);
    return true;
  };

  for (int node : nodes) {
    if (!visited.count(node) && !visit(node)) {
      return {};
    }
  }

  reverse(result.begin(), result.end());
  return result;
}

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

int solve(vector<vector<int>> &sequences, const vector<pair<int, int>> &rules) {
  map<int, set<int>> rule_map;
  for (const auto &[before, after] : rules) {
    rule_map[before].insert(after);
  }

  int sum = 0;
  for (auto &seq : sequences) {
    if (!check_valid_sequence(seq, rule_map)) {
      auto sorted = topological_sort(seq, rule_map);
      if (!sorted.empty()) {
        sum += sorted[sorted.size() / 2];
      }
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