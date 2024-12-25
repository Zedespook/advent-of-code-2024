#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// Global variables
unordered_map<string, long long> button_presses;
const int robot_dir_keypads = 25;

// Function declarations
vector<string> read_door_codes(const string &filename);
string calculate_path_to_button(char from_button, char to_button);
void simulate_numeric_keypad_sequence(const string &code);
void simulate_directional_keypad_sequence(const string &code, long long count);
void process_robot_keypad_chain();
long long calculate_total_complexity(const vector<string> &codes);

int main() {
  vector<string> codes = read_door_codes("day21/input.txt");
  long long complexity_sum = calculate_total_complexity(codes);
  cout << complexity_sum << endl;
  return 0;
}

vector<string> read_door_codes(const string &filename) {
  vector<string> codes;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    codes.push_back(line);
  }
  return codes;
}

string calculate_path_to_button(char from_button, char to_button) {
  map<char, pair<int, int>> keypad = {
      {'7', {0, 0}}, {'8', {1, 0}}, {'9', {2, 0}}, {'4', {0, 1}},
      {'5', {1, 1}}, {'6', {2, 1}}, {'1', {0, 2}}, {'2', {1, 2}},
      {'3', {2, 2}}, {'x', {0, 3}}, {'0', {1, 3}}, {'A', {2, 3}}};

  int x1 = keypad[from_button].first;
  int y1 = keypad[from_button].second;
  int x2 = keypad[to_button].first;
  int y2 = keypad[to_button].second;
  int nx = keypad['x'].first;
  int ny = keypad['x'].second;

  string directions;
  while (make_pair(x1, y1) != make_pair(x2, y2)) {
    if (x2 < x1) {
      if (y1 == ny && x2 == nx) {
        for (int i = 0; i < y1 - y2; ++i) {
          directions += '^';
        }
        y1 = y2;
      } else {
        directions += '<';
        x1--;
      }
    } else if (y2 < y1) {
      directions += '^';
      y1--;
    } else if (y2 > y1) {
      if (x1 == nx && y2 == ny) {
        for (int i = 0; i < x2 - x1; ++i) {
          directions += '>';
        }
        x1 = x2;
      } else {
        directions += 'v';
        y1++;
      }
    } else if (x2 > x1) {
      directions += '>';
      x1++;
    }
  }
  return directions;
}

void simulate_numeric_keypad_sequence(const string &code) {
  char from_button = 'A';
  for (char button : code) {
    string directions = calculate_path_to_button(from_button, button);
    from_button = button;
    directions += 'A';
    button_presses[directions]++;
  }
}

void simulate_directional_keypad_sequence(const string &code, long long count) {
  map<pair<char, char>, string> dir_keypad_moves = {
      {{'A', '^'}, "<A"},   {{'A', '>'}, "vA"},   {{'A', 'v'}, "<vA"},
      {{'A', '<'}, "v<<A"}, {{'^', 'A'}, ">A"},   {{'^', '>'}, "v>A"},
      {{'^', '<'}, "v<A"},  {{'^', 'v'}, "vA"},   {{'v', 'A'}, "^>A"},
      {{'v', '>'}, ">A"},   {{'v', '<'}, "<A"},   {{'v', '^'}, "^A"},
      {{'>', 'A'}, "^A"},   {{'>', '^'}, "<^A"},  {{'>', 'v'}, "<A"},
      {{'>', '<'}, "<<A"},  {{'<', 'A'}, ">>^A"}, {{'<', '^'}, ">^A"},
      {{'<', 'v'}, ">A"},   {{'<', '>'}, ">>A"}};

  char from_button = 'A';
  for (char button : code) {
    string directions;
    if (from_button == button) {
      directions = "A";
    } else {
      directions = dir_keypad_moves[{from_button, button}];
    }
    from_button = button;
    button_presses[directions] += count;
  }
}

void process_robot_keypad_chain() {
  unordered_map<string, long long> iterate_button_presses = button_presses;
  for (const auto &[button_press, count] : iterate_button_presses) {
    simulate_directional_keypad_sequence(button_press, count);
    button_presses[button_press] -= count;
  }
}

long long calculate_total_complexity(const vector<string> &codes) {
  long long complexity_sum = 0;
  for (const string &code : codes) {
    button_presses.clear();
    simulate_numeric_keypad_sequence(code);

    for (int n = 0; n < robot_dir_keypads; ++n) {
      process_robot_keypad_chain();
    }

    long long complexity = 0;
    for (const auto &[button_press, count] : button_presses) {
      complexity += button_press.length() * count;
    }
    complexity_sum += complexity * stoll(code.substr(0, 3));
  }
  return complexity_sum;
}