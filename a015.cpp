#include<iostream>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[j][i]<<' ';
        }
        cout<<'\n';
    }
}
//10 3
//抽10支->10個煙屁股
//10個煙屁股->湊成3支煙＋一個煙屁股
//抽三支煙->4個煙屁股
//四個煙屁股->一支煙＋一個煙屁股
//抽一支煙
//總共抽14支煙