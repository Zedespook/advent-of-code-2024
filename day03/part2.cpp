#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  ll sum = 0;
  bool enabled = true;

  while (getline(cin, s)) {
    for (size_t i = 0; i < s.size() - 3; i++) {
      if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == '(' &&
          s[i + 3] == ')') {
        enabled = true;
        continue;
      }

      if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 'n' &&
          s[i + 3] == '\'') {
        if (i + 6 < s.size() && s[i + 4] == 't' && s[i + 5] == '(' &&
            s[i + 6] == ')') {
          enabled = false;
        }
        continue;
      }

      if (!enabled)
        continue;

      if (s[i] == 'm' && s[i + 1] == 'u' && s[i + 2] == 'l' &&
          s[i + 3] == '(') {
        size_t j = i + 4;
        string x, y;

        while (j < s.size() && isdigit(s[j])) {
          x += s[j++];
        }

        if (j >= s.size() || s[j] != ',' || x.size() > 3)
          continue;
        j++;

        while (j < s.size() && isdigit(s[j])) {
          y += s[j++];
        }

        if (j >= s.size() || s[j] != ')' || y.size() > 3)
          continue;

        if (!x.empty() && !y.empty()) {
          ll num1 = stoll(x);
          ll num2 = stoll(y);
          if (num1 <= 999 && num2 <= 999) {
            sum += num1 * num2;
          }
        }
      }
    }
  }

  cout << sum << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}