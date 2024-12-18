#include <bits/stdc++.h>
using namespace std;

int get_combo_value(int operand, int reg_a, int reg_b, int reg_c) {
  if (operand <= 3)
    return operand;
  if (operand == 4)
    return reg_a;
  if (operand == 5)
    return reg_b;
  if (operand == 6)
    return reg_c;
  throw runtime_error("Invalid operand");
}

vector<int> run_program(const vector<int> &program, int reg_a, int reg_b,
                        int reg_c) {
  vector<int> output;
  int ip = 0;

  while (ip < (int)program.size()) {
    int opcode = program[ip];
    int operand = program[ip + 1];

    switch (opcode) {
    case 0: // adv
      reg_a /= (1 << get_combo_value(operand, reg_a, reg_b, reg_c));
      break;
    case 1: // bxl
      reg_b ^= operand;
      break;
    case 2: // bst
      reg_b = get_combo_value(operand, reg_a, reg_b, reg_c) % 8;
      break;
    case 3: // jnz
      if (reg_a != 0) {
        ip = operand;
        continue;
      }
      break;
    case 4: // bxc
      reg_b ^= reg_c;
      break;
    case 5: // out
      output.push_back(get_combo_value(operand, reg_a, reg_b, reg_c) % 8);
      break;
    case 6: // bdv
      reg_b = reg_a / (1 << get_combo_value(operand, reg_a, reg_b, reg_c));
      break;
    case 7: // cdv
      reg_c = reg_a / (1 << get_combo_value(operand, reg_a, reg_b, reg_c));
      break;
    default:
      throw runtime_error("Invalid opcode");
    }
    ip += 2;
  }

  return output;
}

tuple<int, int, int, vector<int>> read_input() {
  string line;
  int reg_a, reg_b, reg_c;

  getline(cin, line);
  reg_a = stoi(line.substr(line.find(":") + 2));
  getline(cin, line);
  reg_b = stoi(line.substr(line.find(":") + 2));
  getline(cin, line);
  reg_c = stoi(line.substr(line.find(":") + 2));

  getline(cin, line);

  getline(cin, line);
  line = line.substr(line.find(":") + 2); // Remove "Program: "

  vector<int> program;
  stringstream ss(line);
  string num;
  while (getline(ss, num, ',')) {
    program.push_back(stoi(num));
  }

  return {reg_a, reg_b, reg_c, program};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  auto [reg_a, reg_b, reg_c, program] =
      read_input(); // Remove filename parameter
  auto output = run_program(program, reg_a, reg_b, reg_c);

  // Print output
  for (int i = 0; i < (int)output.size(); i++) {
    cout << output[i];
    if (i < (int)output.size() - 1)
      cout << ",";
  }
  cout << "\n";

  return 0;
}