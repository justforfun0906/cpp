#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    stack<char> st;#
    /*st.push(1);
    st.push(2);
    st.empty();//bool
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top();*/
    int t;
    cin>>t;
    while(t--){
        while(!st.empty()){
            st.pop();
        }
        string s;
        cin>>s;
        int cnt = 0;
        bool flag = 1;
        for(int i=0;i<s.length()&&flag;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.empty()){
                    flag = 0;
                }else{
                    st.pop();
                    cnt++;
                }
            }
        }
        if(flag == 0 || !st.empty()){
            cout<<0<<endl;
        }else{
            cout<<cnt<<endl;
        }
    }
}