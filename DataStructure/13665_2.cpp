#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    list<int> li;
    li.push_back(0);
    vector< list<int>::iterator > locate(n + 1, li.begin());
    
    for (int i = 0; i < n; ++i) {
        auto it = locate[x[i]];
        if (s[i] == 'L') {
            locate[i + 1] = li.insert(it, i + 1);
        } else {  // s[i] == 'R'
            locate[i + 1] = li.insert(next(it), i + 1);
        }
    }
    
    for (auto it = li.begin(); it != li.end(); ++it) {
        if (it != li.begin()) cout << ' ';
        cout << *it;
    }
    cout << endl;

    return 0;
}
