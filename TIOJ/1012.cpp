#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    m++;
    int target[n];
    for(int i=0; i<n; i++) cin >> target[i];
    stack<int> origin, temp;
    origin.push(0);
    temp.push(0);
    for(int i=n;i>0;i--){
        origin.push(i);
    }
    for(int i=0;i<n;i++){
        int x=target[i];
        while(origin.top()!=x&&temp.top()!=x){
            if(temp.size()>=m){
                cout<<"no";
                return 0;
            }
            else{
                temp.push(origin.top());
                //cout<<" push"<<temp.top();
                origin.pop();
            }
        }
        if(x==origin.top()){
            //cout<<" drive in(o)"<<origin.top();
            origin.pop();
        }
        else if(x==temp.top()){
            //cout<<" drive in(t)"<<temp.top();
            temp.pop();
        }
        else if(x>temp.top()){
            cout<<"no";
            return 0;
        }
    }
    cout << "yes";
}