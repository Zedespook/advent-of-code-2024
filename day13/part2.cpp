#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
  while (b) {
    int64_t t = b;
    b = a % b;
    a = t;
  }
  return abs(a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  int64_t total_tokens = 0;
  [[maybe_unused]] int solvable = 0;
  const int64_t OFFSET = 10000000000000LL;

  while (getline(cin, line)) {
    if (line.empty())
      continue;

    regex pattern("X\\+(\\d+), Y\\+(\\d+)");
    smatch matches;
    regex_search(line, matches, pattern);
    int64_t a_x = stoll(matches[1]);
    int64_t a_y = stoll(matches[2]);

    getline(cin, line);
    regex_search(line, matches, pattern);
    int64_t b_x = stoll(matches[1]);
    int64_t b_y = stoll(matches[2]);

    getline(cin, line);
    regex pattern2("X=(\\d+), Y=(\\d+)");
    regex_search(line, matches, pattern2);
    int64_t prize_x = stoll(matches[1]) + OFFSET;
    int64_t prize_y = stoll(matches[2]) + OFFSET;

    int64_t det = a_x * b_y - a_y * b_x;
    if (det == 0)
      continue;

    long double a =
        (prize_x * (long double)b_y - prize_y * (long double)b_x) / det;
    long double b =
        (a_x * (long double)prize_y - a_y * (long double)prize_x) / det;

    if (a >= 0 && b >= 0 && abs(a - roundl(a)) < 1e-10 &&
        abs(b - roundl(b)) < 1e-10) {
      int64_t a_int = roundl(a);
      int64_t b_int = roundl(b);
      total_tokens += 3 * a_int + b_int;
      solvable++;
    }
  }

  cout << total_tokens << '\n';
  return 0;
}