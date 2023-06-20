#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    int target[n];
    for(int i=0; i<n; i++) cin >> target[i];
    stack<int> origin, temp;
    for(int i=n;i>0;i--){
        origin.push(i);
    }
    cout<<"check1"<<"\n";
    bool flag=1;
    for(int i=0;i<n;i++){
        cout<<"origin top="<<origin.top()<<" temp top="<<temp.top()<<'\n';
        while(target[i]!=origin.top()&&target[i]!=temp.top()){
            if(temp.size()<m){
                temp.push(origin.top());
                origin.pop();
            }
            else if(temp.size()>=m||origin.empty()) flag=0;
            if(flag==0) break;
        }
        if(origin.top()==target[i])origin.pop();
        else if(temp.top()==target[i])temp.pop();
        if(flag==0) break;
    }
    if(!flag)cout<<"no";
    else cout<<"yes";
}