#include<bits/stdc++.h>
using namespace std;
bool isLeftParen(char c){
    return c == '(' || c == '[';
}
bool check(string &s){
    int n = s.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(isLeftParen(s[i])){
            st.push(s[i]);
        }else{
            if(st.empty())return false;
            if(s[i] == ')' && st.top() == '('){
                st.pop();
            }else if(s[i] == ']' && st.top() == '['){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    //ios_base::sync_with_stdio(0);
    int q;
    cin>>q;
    getchar();
    while(q--){
        char c;
        string s;
        c = getchar();
        if(c == '\n' || c == EOF){
            cout<<"N";
        }else{
            while(c != '\n' && c != EOF){
                s.push_back(c);
                c = getchar();
            }
            check(s)?cout<<"Y":cout<<"N";
        }
        if(q!=0)cout<<'\n';
    }
}