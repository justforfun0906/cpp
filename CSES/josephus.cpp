#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int next[n+1], prev[n+1];   
    for(int i=0;i<n-1;i++){
        next[i] = i+1;
        prev[i] = i-1;
    }
    prev[n-1] = n-2;
    prev[0] = n-1;
    next[n-1] = 0;
    int now = 0;
    int count = 1;
    while(next[now]!=now){
        if(count == m%n){
            cout<<now+1<<" ";
            next[prev[now]] = next[now];
            prev[next[now]] = prev[now];
            count = 1;
        }
        else{
            count++;
        }
        now = next[now];
    }
    cout<<now+1;
}