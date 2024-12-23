#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool are_all_connected(
    const vector<string> &group,
    const unordered_map<string, unordered_set<string>> &adj) {
  for (size_t i = 0; i < group.size(); ++i) {
    for (size_t j = i + 1; j < group.size(); ++j) {
      if (adj.at(group[i]).count(group[j]) == 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  string filename = "day23/input.txt";
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return 1;
  }

  unordered_map<string, unordered_set<string>> adj;
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    string first, second;
    getline(ss, first, '-');
    getline(ss, second);
    adj[first].insert(second);
    adj[second].insert(first);
  }

  vector<string> computers;
  for (const auto &pair : adj) {
    computers.push_back(pair.first);
  }
  sort(computers.begin(), computers.end());

  vector<string> largest_group;

  // Iterate through each computer as a potential starting point for the largest
  // group
  for (const string &start_computer : computers) {
    vector<string> current_group;
    current_group.push_back(start_computer);

    // Expand the current group by adding connected computers
    for (size_t i = 0; i < current_group.size(); ++i) {
      const string &current_computer = current_group[i];
      for (const string &neighbor : adj[current_computer]) {
        // Add neighbor to the group if it's not already present and maintains
        // connectivity
        if (find(current_group.begin(), current_group.end(), neighbor) ==
            current_group.end()) {
          bool all_connected = true;
          for (const string &existing_member : current_group) {
            if (adj[neighbor].count(existing_member) == 0) {
              all_connected = false;
              break;
            }
          }
          if (all_connected) {
            current_group.push_back(neighbor);
          }
        }
      }
    }

    // Sort the current group for consistent comparison
    sort(current_group.begin(), current_group.end());

    // Update the largest group if the current group is larger
    if (current_group.size() > largest_group.size()) {
      largest_group = current_group;
    }
  }

  string password;
  for (size_t i = 0; i < largest_group.size(); ++i) {
    password += largest_group[i];
    if (i < largest_group.size() - 1) {
      password += ",";
    }
  }

  cout << password << endl;

  return 0;
}
