#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n;
    m = n;
    int a[n+1];
    int cnt = 0;
    for(int i=0;i<n+1;i++){
        a[i] = 0;
    }
    //[0 0 0 0 0 0]
    for(int i=2;i<=m;i++){
        while(m%i == 0){
            m = m / i;
            a[i] = a[i] + 1;
        }
    }
    //[0 2 0 0 1] a[i] = i的次數
    for(int i=0;i<=n;i++){
        cnt += a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]>0){
            //2^2 i = 2, a[i] = 2
            //5, i = 5, a[i] = 1
            cnt -= a[i];
            if(a[i] == 1){
                cout<<i;
            }else{
                cout<<i<<'^'<<a[i];
            }
            if(cnt>0){
                cout<<" * ";
            }
        }
    }
    cout<<'\n';
}