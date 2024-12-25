#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<pair<char, char>, string> dir_base_lookup = {
    {{'A', 'A'}, "A"},    {{'^', '^'}, "A"},   {{'>', '>'}, "A"},
    {{'v', 'v'}, "A"},    {{'<', '<'}, "A"},   {{'A', '^'}, "<A"},
    {{'^', 'A'}, ">A"},   {{'A', '>'}, "vA"},  {{'>', 'A'}, "^A"},
    {{'v', '^'}, "^A"},   {{'^', 'v'}, "vA"},  {{'v', '<'}, "<A"},
    {{'<', 'v'}, ">A"},   {{'v', '>'}, ">A"},  {{'>', 'v'}, "<A"},
    {{'A', 'v'}, "v<A"},  {{'v', 'A'}, ">^A"}, {{'A', '<'}, "v<<A"},
    {{'<', 'A'}, ">>^A"}, {{'>', '<'}, "<<A"}, {{'<', '>'}, ">>A"},
    {{'<', '^'}, ">^A"},  {{'^', '<'}, "v<A"}, {{'>', '^'}, "<^A"},
    {{'^', '>'}, "v>A"}};

vector<vector<pair<char, int>>> dirs = {
    {make_pair('^', -1), make_pair('v', 1)},
    {make_pair('<', -1), make_pair('>', 1)}};

vector<vector<char>> numpad = {
    {'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'}, {' ', '0', 'A'}};

map<char, pair<int, int>> numpad_lookup = {
    {'7', {0, 0}}, {'8', {0, 1}}, {'9', {0, 2}}, {'4', {1, 0}},
    {'5', {1, 1}}, {'6', {1, 2}}, {'1', {2, 0}}, {'2', {2, 1}},
    {'3', {2, 2}}, {' ', {3, 0}}, {'0', {3, 1}}, {'A', {3, 2}}};

vector<vector<char>> dirpad = {{' ', '^', 'A'}, {'<', 'v', '>'}};

map<char, pair<int, int>> dirpad_lookup = {{' ', {0, 0}}, {'^', {0, 1}},
                                           {'A', {0, 2}}, {'<', {1, 0}},
                                           {'v', {1, 1}}, {'>', {1, 2}}};

map<pair<pair<char, char>, int>, string> memo_dir;

string dir_dfs(char key_start, char key_end, int depth = 0) {
  if (depth == 0) {
    return dir_base_lookup[{key_start, key_end}];
  }

  auto key = make_pair(make_pair(key_start, key_end), depth);
  if (memo_dir.find(key) != memo_dir.end()) {
    return memo_dir[key];
  }

  string s = dir_dfs(key_start, key_end, depth - 1);
  string out;
  char prev = 'A';
  for (char curr : s) {
    out += dir_base_lookup[{prev, curr}];
    prev = curr;
  }

  memo_dir[key] = out;
  return out;
}

string num_solve(char key_start, char key_end) {
  auto [y0, x0] = numpad_lookup[key_start];
  auto [y1, x1] = numpad_lookup[key_end];
  int y_dist = y1 - y0;
  int x_dist = x1 - x0;
  auto [y_key, y_dir] = dirs[0][y_dist > 0];
  auto [x_key, x_dir] = dirs[1][x_dist > 0];

  string start_move;
  string mov_s;

  if ((y0 == 3 || y1 == 3) && (x0 == 0 || x1 == 0)) {
    if (x0 == 0) {
      start_move = ">";
      mov_s = string(abs(y_dist), y_key) + string(abs(x_dist) - 1, x_key);
    } else {
      start_move = "^";
      mov_s = string(abs(y_dist) - 1, y_key) + string(abs(x_dist), x_key);
    }
  } else {
    mov_s = string(abs(y_dist), y_key) + string(abs(x_dist), x_key);
  }

  set<string> possible_inputs;
  string temp = mov_s;
  sort(temp.begin(), temp.end());
  do {
    possible_inputs.insert("A" + start_move + temp + "A");
  } while (next_permutation(temp.begin(), temp.end()));

  int min_score = INT_MAX;
  string min_inputs;

  for (const auto &inputs : possible_inputs) {
    string sequence;
    char prev = inputs[0];
    for (size_t i = 1; i < inputs.length(); ++i) {
      sequence += dir_dfs(prev, inputs[i], 1);
      prev = inputs[i];
    }

    if (static_cast<int>(sequence.length()) < min_score) {
      min_score = sequence.length();
      min_inputs = sequence;
    }
  }

  return min_inputs;
}

int main() {
  ifstream inFile("day21/input.txt");
  string code;
  long long out = 0;

  while (getline(inFile, code)) {
    int m = stoi(code.substr(0, code.length() - 1));
    string s;
    char prev = 'A';
    for (char curr : code) {
      s += num_solve(prev, curr);
      prev = curr;
    }
    out += s.length() * m;
  }

  cout << out << endl;
  return 0;
}
