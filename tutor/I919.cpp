#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool isMono = 1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            isMono = 0;
            break;
        }
    }
    if(isMono){
        cout<<-1;
    }else{
        int maxV = 0;
        int buyL, sellL;
        for(int i=1;i<n;i++){
            for(int j = i+1;j<=n;j++){
                if((a[j] - a[i])>maxV){
                    maxV = a[j] - a[i];
                    sellL = j;
                    buyL = i;
                }
            }
        }
        cout<<buyL<<' '<<sellL;
    }
}