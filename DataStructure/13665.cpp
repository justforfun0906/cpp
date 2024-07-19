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
    vector< list<int>::iterator > locate(n + 5, li.begin());
    list<int>::iterator now = li.begin();
    
    for (int i = 0; i < n; ++i) {
        if(*locate[x[i]] == x[i]) {
            now = locate[x[i]];
            //cout<<"found "<<x[i]<<'\n';
        }else{
            for(auto it = li.begin(); it != li.end(); ++it){
                if(*it == x[i]){
                    now = it;
                    break;
                }
            }
        }
        if (s[i] == 'L') {
            li.insert(now, i + 1);
            if (now == li.begin()) now = li.begin();
            else now--;
        } else {
            if (now == li.end()) {
                li.push_back(i + 1);
                now = li.end();
                now--;
            } else {
                li.insert(++now, i + 1);
            }
        }
        locate[i + 1] = now;
    }
    
    for (auto it = li.begin(); it != li.end(); ++it) {
        if (it != li.begin()) cout << ' ';
        cout << *it;
    }
    cout << endl;

    return 0;
}
