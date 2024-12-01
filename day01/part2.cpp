#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> left;
    unordered_map<int, int> right_counts;
    
    int x, y;
    while (cin >> x >> y) {
        left.push_back(x);
        right_counts[y]++;
    }
    
    ll similarity_score = 0;
    for (int num : left) {
        similarity_score += (ll)num * right_counts[num];
    }
    
    cout << similarity_score << endl;
    
    return 0;
}