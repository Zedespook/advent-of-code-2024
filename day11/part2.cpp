#include <bits/stdc++.h>
using namespace std;

vector<long long> blink(long long rock) {
  if (rock == 0) {
    return {1};
  }

  string rock_str = to_string(rock);
  int rock_len = rock_str.length();

  if (rock_len % 2 == 0) {
    int mid = rock_len / 2;
    return {stoll(rock_str.substr(0, mid)), stoll(rock_str.substr(mid))};
  } else {
    return {2024 * rock};
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  map<long long, long long> rock_count;
  long long rock;
  while (cin >> rock) {
    rock_count[rock]++;
  }

  for (int i = 0; i < 75; i++) {
    map<long long, long long> new_counts;

    for (const auto &[rock, count] : rock_count) {
      vector<long long> new_rocks = blink(rock);
      for (long long new_rock : new_rocks) {
        new_counts[new_rock] += count;
      }
    }

    rock_count = new_counts;
  }

  __int128_t total = 0;
  for (const auto &[_, count] : rock_count) {
    total += count;
  }

  string result;
  __int128_t temp = total;
  do {
    result = char('0' + (temp % 10)) + result;
    temp /= 10;
  } while (temp > 0);

  cout << result << '\n';
  return 0;
}