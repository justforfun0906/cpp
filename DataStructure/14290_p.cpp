#include<bits/stdc++.h>
using namespace std;
//shunting yard algorithm
int main(){
    string expr;
    cin>>expr;
    stack<char> operations;
    vector<char> postfix;
    unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    for(auto c:expr){
        if(isalpha(c)){
            postfix.push_back(c);
        }else{
            //priority: bracket-> */ -> +-
            if(c == '('){
                operations.push(c);
            }else if(c == ')'){
                while(!operations.empty() && operations.top()!= '('){
                    postfix.push_back(operations.top());
                    operations.pop();
                }
                operations.pop();
            }else{
                while(!operations.empty() &&
                priority[operations.top()]>=priority[c] &&
                operations.top()!= '('){
                    //the operations in the stack go first
                    postfix.push_back(operations.top());
                    operations.pop();
                }
                operations.push(c);
            }
        }
    }
    while(!operations.empty()){
        postfix.push_back(operations.top());
        operations.pop();
    }
    int q;
    cin>>q;
    while(q--){
        int n = 5;
        vector<int> value(5);
        for(int i=0;i<n;i++){
            cin>>value[i];
        }
        stack<int> s;
        for(char c:postfix){
            if(isalpha(c)){
                s.push(value[c-'A']);
            }else{
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if(c=='+') s.push(a+b);
                else if(c == '-') s.push(a-b);
                else if(c == '*') s.push(a*b);
                else s.push(a/b);
            }
        }
        cout<<s.top();
        if(q)cout<<'\n';
    }
}