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

int countTrianglesWithT(const Graph &graph) {
  int count = 0;
  std::vector<std::string> nodes;
  for (const auto &[node, _] : graph) {
    nodes.push_back(node);
  }

  for (size_t i = 0; i < nodes.size(); i++) {
    for (size_t j = i + 1; j < nodes.size(); j++) {
      if (!graph.at(nodes[i]).count(nodes[j]))
        continue;

      for (size_t k = j + 1; k < nodes.size(); k++) {
        if (graph.at(nodes[i]).count(nodes[k]) &&
            graph.at(nodes[j]).count(nodes[k])) {
          if (nodes[i][0] == 't' || nodes[j][0] == 't' || nodes[k][0] == 't') {
            count++;
          }
        }
      }
    }
  }

  return count;
}

int main() {
  auto graph = buildGraph("day23/input.txt");
  std::cout << countTrianglesWithT(graph) << std::endl;
  return 0;
}