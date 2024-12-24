#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using Graph = std::unordered_map<std::string, std::unordered_set<std::string>>;

Graph buildGraph(const std::string &filename) {
  Graph graph;
  std::ifstream file(filename);
  std::string line;

  while (std::getline(file, line)) {
    std::string a = line.substr(0, line.find('-'));
    std::string b = line.substr(line.find('-') + 1);
    graph[a].insert(b);
    graph[b].insert(a);
  }

  return graph;
}

bool isClique(const Graph &graph, const std::vector<std::string> &group) {
  for (size_t i = 0; i < group.size(); i++) {
    for (size_t j = i + 1; j < group.size(); j++) {
      if (!graph.at(group[i]).count(group[j])) {
        return false;
      }
    }
  }
  return true;
}

std::vector<std::string> findLargestClique(const Graph &graph) {
  std::vector<std::string> nodes;
  for (const auto &[node, _] : graph) {
    nodes.push_back(node);
  }
  std::sort(nodes.begin(), nodes.end());

  std::vector<std::string> maxClique;
  std::vector<std::string> currentGroup;

  // Try each node as a starting point
  for (const auto &start : nodes) {
    currentGroup = {start};
    std::vector<std::string> candidates;

    // Find all nodes connected to start
    for (const auto &neighbor : graph.at(start)) {
      candidates.push_back(neighbor);
    }

    // Try adding each candidate
    for (const auto &candidate : candidates) {
      bool canAdd = true;
      for (const auto &node : currentGroup) {
        if (!graph.at(candidate).count(node)) {
          canAdd = false;
          break;
        }
      }
      if (canAdd) {
        currentGroup.push_back(candidate);
      }
    }

    if (currentGroup.size() > maxClique.size()) {
      maxClique = currentGroup;
    }
  }

  std::sort(maxClique.begin(), maxClique.end());
  return maxClique;
}

int main() {
  auto graph = buildGraph("day23/input.txt");
  auto clique = findLargestClique(graph);

  // Print the password
  for (size_t i = 0; i < clique.size(); i++) {
    std::cout << clique[i];
    if (i < clique.size() - 1)
      std::cout << ",";
  }
  std::cout << std::endl;

  return 0;
}