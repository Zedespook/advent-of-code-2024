#include <bits/stdc++.h>
using namespace std;

int countDigits(long long n) {
  if (n == 0)
    return 1;
  int count = 0;
  while (n) {
    n /= 10;
    count++;
  }
  return count;
}

pair<long long, long long> splitNumber(long long n) {
  string s = to_string(n);
  int mid = s.length() / 2;
  return {stoll(s.substr(0, mid)), stoll(s.substr(mid))};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<long long, int>> stones;
  long long stone;

  while (cin >> stone) {
    stones.push_back({stone, 1});
  }

  for (int i = 0; i < 25; i++) {
    vector<pair<long long, int>> next;
    for (auto [value, count] : stones) {
      if (value == 0) {
        next.push_back({1, count});
      } else if (countDigits(value) % 2 == 0) {
        auto [left, right] = splitNumber(value);
        next.push_back({left, count});
        next.push_back({right, count});
      } else {
        next.push_back({value * 2024LL, count});
      }
    }
    stones = next;
  }

  long long total = 0;
  for (auto [_, count] : stones) {
    total += count;
  }

  cout << total << '\n';
  return 0;
}