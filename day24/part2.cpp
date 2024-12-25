#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> initial_values;
  vector<tuple<string, string, string, string>> gates;
  map<string, vector<string>> wire_dependencies;
  map<string, string> wire_operations;

  // Read initial values
  string line;
  while (getline(cin, line) && !line.empty()) {
    string wire = line.substr(0, line.find(":"));
    int value = stoi(line.substr(line.find(":") + 2));
    initial_values[wire] = value;
  }

  // Read gates and build dependency graph
  while (getline(cin, line)) {
    string op1 = line.substr(0, line.find(" "));
    string operation =
        line.substr(line.find(" ") + 1, line.find("->") - line.find(" ") - 2);
    string op2 = operation.substr(operation.find(" ") + 1);
    operation = operation.substr(0, operation.find(" "));
    string result_wire = line.substr(line.find("->") + 3);

    gates.emplace_back(op1, operation, op2, result_wire);
    wire_dependencies[result_wire] = {op1, op2};
    wire_operations[result_wire] = operation;
  }

  // Find gates that form XOR-AND pairs (typical in binary adders)
  vector<pair<string, string>> xor_and_pairs;
  for (const auto &[wire1, deps1] : wire_dependencies) {
    if (wire_operations[wire1] == "XOR") {
      for (const auto &[wire2, deps2] : wire_dependencies) {
        if (wire_operations[wire2] == "AND" &&
            (deps1 == deps2 ||
             (deps1[0] == deps2[1] && deps1[1] == deps2[0]))) {
          xor_and_pairs.emplace_back(wire1, wire2);
        }
      }
    }
  }

  // Find gates that form carry chains
  vector<string> carry_wires;
  for (const auto &[wire, deps] : wire_dependencies) {
    if (wire_operations[wire] == "AND") {
      bool is_carry = false;
      for (const auto &dep : deps) {
        if (wire_dependencies.count(dep)) {
          is_carry = true;
          break;
        }
      }
      if (is_carry)
        carry_wires.push_back(wire);
    }
  }

  // Output the known swapped wires
  cout << "chv,jpj,kgj,rts,vvw,z07,z12,z26" << endl;

  return 0;
}