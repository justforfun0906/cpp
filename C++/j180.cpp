#include<bits/stdc++.h>
using namespace std;
int w[505];
int cnt=0;
int main(){
    int n,q;
    while(cin>>n){
        if(n==-1)break;
        cin>>q;
        for(int i=0;i<n;i++)w[i]=q;
        while(w[0]>0){
        	for(int i=0;i<n;i++){
                cout<<w[i]<<" ";
            }
            cout<<'\n';
            
            if(w[n-1]==0)n--;
            for(int i=0;i<n;i++){
                w[i]--;
            }
            for(int i=0;i<w[n-1];i++){
                    if(i<n-1){
                        w[i]++;
                        w[n-1]--;
                    }
                }
            cnt++;
        }
        cout<<cnt<<'\n';
        cnt=0;
    }
}
