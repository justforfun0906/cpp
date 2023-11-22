#include<iostream>
using namespace std;
int main(){
    bool cnt[105][105];
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            cnt[i][j]=0;
        }
    }
    int n; cin>>n;
    while(n--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int i=a;i<b;i++){
            for(int j=c;j<d;j++){
                cnt[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(cnt[i][j])ans++;
        }
    }
    cout<<ans;
}