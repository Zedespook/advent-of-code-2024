#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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

  int count = 0;
  int n = computers.size();
  int total_iterations = n * (n - 1) * (n - 2) / 6;
  int current_iteration = 0;
  auto start_time = chrono::high_resolution_clock::now();

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        current_iteration++;

        // Progress indicator (every 1% of progress)
        if (current_iteration % (total_iterations / 100) == 0) {
          auto current_time = chrono::high_resolution_clock::now();
          auto elapsed_time =
              chrono::duration_cast<chrono::seconds>(current_time - start_time)
                  .count();
          double progress = (double)current_iteration / total_iterations;
          double estimated_remaining_time =
              (elapsed_time / progress) - elapsed_time;

          cout << "Progress: " << (progress * 100) << "%";
          if (elapsed_time > 0) {
            cout << ", Estimated time remaining: " << estimated_remaining_time
                 << " seconds";
          }
          cout << "\r" << flush;
        }

        const string &c1 = computers[i];
        const string &c2 = computers[j];
        const string &c3 = computers[k];

        if (adj[c1].count(c2) && adj[c1].count(c3) && adj[c2].count(c3)) {
          if (c1[0] == 't' || c2[0] == 't' || c3[0] == 't') {
            count++;
          }
        }
      }
    }
  }

  cout << endl << "Result: " << count << endl;

  return 0;
}
