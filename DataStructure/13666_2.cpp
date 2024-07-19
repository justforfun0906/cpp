#include <bits/stdc++.h>
using namespace std;

string ans(const string& S) {
    deque<char> dq;
    for (char c : S) {
        dq.push_back(c);
        if (dq.size() >= 3) {
            int n = dq.size();
            if (dq[n-3] == 'A' && dq[n-2] == 'B' && dq[n-1] == 'C') {
                dq.pop_back();
                dq.pop_back();
                dq.pop_back();
            }
        }
    }

    // Convert deque back to string
    string rt(dq.begin(), dq.end());
    return rt;
}

int main() {
    string S;
    cin >> S;
    cout << ans(S) << '\n';
}
