#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,b;
    int now=1;
    while(cin>>a>>b&&a!=0&&b!=0){
        cout<<"Twin Towers #"<<now<<'\n';
        now++;
        int arr1[a], arr2[b];
        int dp[a+5][b+5];
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<a;i++)cin>>arr1[i];
        for(int i=0;i<b;i++)cin>>arr2[i];
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(arr1[i-1]==arr2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
        cout<<"Number of Tiles : ";
        cout<<dp[a][b]<<'\n'<<'\n';
    }
}