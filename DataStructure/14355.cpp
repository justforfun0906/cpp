#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    queue<int> a;
    for(int i = 1;i<=n;i++){
        a.push(i);
    }
    stack<int> st;
    for(int i=0;i<n;i++){
        int target;
        cin>>target;
        if(st.empty()){
            st.push(a.front());
            a.pop();
            cout<<"Push\n";
        }
        while(st.top()!=target){
            if(a.empty()){
                cout<<"NO\n";
                return 0;
            }
            st.push(a.front());
            a.pop();
            cout<<"Push\n";
        }
        st.pop();
        cout<<"Pop\n";
    }
}