#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool can_make_value(ll target, vector<ll> &nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0] == target;

  // Try all possible operator combinations
  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    ll result = nums[0];
    for (int i = 1; i < n; i++) {
      // If bit is set, use multiplication, else addition
      if (mask & (1 << (i - 1))) {
        result *= nums[i];
      } else {
        result += nums[i];
      }
    }
    if (result == target)
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  ll sum = 0;

  while (getline(cin, line)) {
    stringstream ss(line);
    ll target;
    char colon;
    ss >> target >> colon;

    vector<ll> nums;
    ll num;
    while (ss >> num) {
      nums.push_back(num);
    }

    if (can_make_value(target, nums)) {
      sum += target;
    }
  }

  cout << sum << endl;
  return 0;
}