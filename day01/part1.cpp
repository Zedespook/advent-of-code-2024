#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> left, right;
    int x, y;
    
    while (cin >> x >> y) {
        left.push_back(x);
        right.push_back(y);
    }
    
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    
    ll total_distance = 0;
    for (size_t i = 0; i < left.size(); i++) {
        total_distance += abs(left[i] - right[i]);
    }
    
    cout << total_distance << endl;
    
    return 0;
}