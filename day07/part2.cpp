#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll concat(ll a, ll b) {
  string s_b = to_string(b);
  return stoll(to_string(a) + s_b);
}

bool can_make_value(ll target, vector<ll> &nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0] == target;

  for (int mask = 0; mask < pow(3, n - 1); mask++) {
    ll result = nums[0];
    int temp_mask = mask;

    for (int i = 1; i < n; i++) {
      int op = temp_mask % 3;
      temp_mask /= 3;

      if (op == 0) {
        result += nums[i];
      } else if (op == 1) {
        result *= nums[i];
      } else {
        result = concat(result, nums[i]);
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