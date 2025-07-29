#include<stack>
#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n && n){
        while(true){
            int a[n];
            stack<int> st;
            int idx = 1;
            cin>>a[0];
            if(a[0] == 0) break;
            for(int i = 1;i<n;i++){
                cin>>a[i];
            }
            int i;
            for(i=0;i<n;i++){
                if(!st.empty() && st.top() == a[i]){
                    st.pop();
                }else if(a[i] >= idx){
                    while(idx < a[i]){
                        st.push(idx);
                        idx++;
                    }
                    idx = a[i] + 1;
                }else{
                    break;
                }
            }
            if(i==n){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
        cout<<"\n";
    }
}