#include<iostream>
using namespace std;
int pos[300005];
int result[300005];
int main(){
    int n, head;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(temp==-1) head = i;
        else pos[temp] = i;
    }
    for(int i=0;i<n;i++){
        cout<<head<<' ';
        head = pos[head];
    }
}