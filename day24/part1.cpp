#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> initial_values;
  vector<tuple<string, string, string, string>> gates;

  string line;
  while (getline(cin, line) && !line.empty()) {
    string wire = line.substr(0, line.find(":"));
    int value = stoi(line.substr(line.find(":") + 2));
    initial_values[wire] = value;
  }

  while (getline(cin, line)) {
    string op1 = line.substr(0, line.find(" "));
    string operation =
        line.substr(line.find(" ") + 1, line.find("->") - line.find(" ") - 2);
    string op2 = operation.substr(operation.find(" ") + 1);
    operation = operation.substr(0, operation.find(" "));
    string result_wire = line.substr(line.find("->") + 3);
    gates.emplace_back(op1, operation, op2, result_wire);
  }

  map<string, int> wire_values = initial_values;
  bool changed = true;
  while (changed) {
    changed = false;
    for (const auto &gate : gates) {
      string op1, operation, op2, result_wire;
      tie(op1, operation, op2, result_wire) = gate;

      if (wire_values.count(op1) && wire_values.count(op2) &&
          !wire_values.count(result_wire)) {
        int val1 = wire_values[op1];
        int val2 = wire_values[op2];
        int result;

        if (operation == "AND") {
          result = val1 & val2;
        } else if (operation == "OR") {
          result = val1 | val2;
        } else if (operation == "XOR") {
          result = val1 ^ val2;
        }

        wire_values[result_wire] = result;
        changed = true;
      }
    }
  }

  string binary_result;
  for (int i = 0;; ++i) {
    string wire_name = "z" + string(i < 10 ? "0" : "") + to_string(i);
    if (wire_values.count(wire_name)) {
      binary_result += to_string(wire_values[wire_name]);
    } else {
      break;
    }
  }

  reverse(binary_result.begin(), binary_result.end());
  long long decimal_result = stoll(binary_result, nullptr, 2);
  cout << decimal_result << endl;

  return 0;
}
