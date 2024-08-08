#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> build(int n, vector<int>& pre, vector<int>& in) {
    if (n == 0) return {};
    int root = pre[0];
    
    int root_idx = find(in.begin(), in.end(), root) - in.begin();
    if (root_idx == n) return {};  // In case root not found, should never happen with valid input.
    
    vector<int> left_pre(pre.begin() + 1, pre.begin() + 1 + root_idx);
    vector<int> right_pre(pre.begin() + 1 + root_idx, pre.end());
    vector<int> left_in(in.begin(), in.begin() + root_idx);
    vector<int> right_in(in.begin() + root_idx + 1, in.end());
    
    vector<int> left = build(root_idx, left_pre, left_in);
    vector<int> right = build(n - root_idx - 1, right_pre, right_in);
    
    vector<int> ans;
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    ans.push_back(root);
    return ans;
}

void solve() {
    int n;
    cin >> n;
  
    vector<int> pre(n), in(n), post(n);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    
    vector<int> ans = build(n, pre, in);
    if (ans == post) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
