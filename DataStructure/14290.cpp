#include <bits/stdc++.h>
using namespace std;

int main() {
    string expr;
    cin >> expr;
    stack<char> ope;
    vector<char> post;

    for (char c : expr) {
        if (isalpha(c)) {
            post.push_back(c);
        } else {
            if (c == '(') {
                ope.push(c);
            } else if (c == ')') {
                while (!ope.empty() && ope.top() != '(') {
                    post.push_back(ope.top());
                    ope.pop();
                }
                if (!ope.empty()) {
                    ope.pop(); // pop '('
                }
            } else if (c == '+' || c == '-') {
                while (!ope.empty() && ope.top() != '(') {
                    post.push_back(ope.top());
                    ope.pop();
                }
                ope.push(c);
            } else if (c == '*' || c == '/') {
                while (!ope.empty() && (ope.top() == '*' || ope.top() == '/')) {
                    post.push_back(ope.top());
                    ope.pop();
                }
                ope.push(c);
            }
        }
    }

    while (!ope.empty()) {
        post.push_back(ope.top());
        ope.pop();
    }

    int q; cin>>q;
    vector<int> val(5);
    while(q--){
        for(int i=0;i<5;i++){
            cin>>val[i];
        }
        // calculate
        stack<int> s;
        for(char c : post){
            if(isalpha(c)){
                s.push(val[c-'A']);
            }else{
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if(c == '+') s.push(a+b);
                else if(c == '-') s.push(a-b);
                else if(c == '*') s.push(a*b);
                else if(c == '/') s.push(a/b);
            }
        }
        cout<<s.top();
        if(q) cout<<"\n";
    }
    return 0;
}