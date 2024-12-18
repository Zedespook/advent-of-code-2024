#include <bits/stdc++.h>
using namespace std;

enum OP_CODE {
  adv = 0,
  bxl = 1,
  bst = 2,
  jnz = 3,
  bxc = 4,
  output = 5,
  bdv = 6,
  cdv = 7
};

// Because life is too short to write long names
using i64 = long long;

i64 combo(const vector<i64> &registers, i64 value) {
  if (value >= 0 && value <= 3)
    return value;
  return registers[value - 4];
}

vector<i64> run(const vector<i64> &program, i64 a, i64 b, i64 c) {
  vector<i64> registers = {a, b, c};
  vector<i64> output;
  i64 ip = 0;

  while (ip < static_cast<i64>(program.size())) {
    OP_CODE opCode = static_cast<OP_CODE>(program[ip]);
    i64 operand = program[ip + 1];

    switch (opCode) {
    case OP_CODE::adv:
      registers[0] =
          registers[0] / (1LL << static_cast<int>(combo(registers, operand)));
      break;
    case OP_CODE::bxl:
      registers[1] = registers[1] ^ operand;
      break;
    case OP_CODE::bst:
      registers[1] = combo(registers, operand) % 8;
      break;
    case OP_CODE::jnz:
      if (registers[0] != 0) {
        ip = operand;
        ip -= 2;
      }
      break;
    case OP_CODE::bxc:
      registers[1] = registers[1] ^ registers[2];
      break;
    case OP_CODE::output:
      output.push_back(combo(registers, operand) % 8);
      break;
    case OP_CODE::bdv:
      registers[1] =
          registers[0] / (1LL << static_cast<int>(combo(registers, operand)));
      break;
    case OP_CODE::cdv:
      registers[2] =
          registers[0] / (1LL << static_cast<int>(combo(registers, operand)));
      break;
    }
    ip += 2;
  }
  return output;
}

vector<string> split(const string &s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    if (!token.empty())
      tokens.push_back(token);
  }
  return tokens;
}

bool sequenceEqual(const vector<i64> &a, const vector<i64> &b,
                   size_t startIdx) {
  if (startIdx >= a.size() || startIdx >= b.size())
    return false;
  return equal(a.begin() + startIdx, a.end(), b.begin() + startIdx);
}

int main() {
  string line;
  vector<i64> registers;
  vector<i64> program;

  // Read registers
  for (int i = 0; i < 3; i++) {
    getline(cin, line);
    auto parts = split(line, ':');
    registers.push_back(stoll(parts[1]));
  }

  // Skip empty line
  getline(cin, line);

  // Read program
  getline(cin, line);
  auto parts = split(line, ':');
  auto numbers = split(parts[1], ',');
  for (const auto &num : numbers) {
    program.push_back(stoll(num));
  }

  i64 current = 0;
  for (int digit = program.size() - 1; digit >= 0; digit--) {
    for (i64 i = 0; i < INT_MAX; i++) {
      i64 candidate = current + (1LL << (digit * 3)) * i;
      auto output = run(program, candidate, 0, 0);

      if (sequenceEqual(output, program, digit)) {
        current = candidate;
        break;
      }
    }
  }

  cout << current << endl;

  return 0;
}