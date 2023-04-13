#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    queue<int> q;
    while(t--){
        int k;
        cin>>k;
        if(k==1){
            int n;
            cin>>n;
            q.push(n);
            //cout<<"push "<<n<<'\n';
        }
        else{
            if(q.empty()) cout<<"empty!"<<'\n';
            else{
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
    }
}
