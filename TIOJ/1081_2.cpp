#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m&&(n!=0&&m!=0)){
        queue<pair<int, int> > bfs;
        string s[n+1];
        for(int i=0;i<n;i++)cin>>s[i];
        int cnt=0;
        bool arr[n+5][m+5]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) arr[i][j]=s[i-1][j-1]-'0';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j]){
                    cnt++;
                    bfs.push(make_pair(i,j)) ;
                    arr[i][j]=0;
                }
                while(!bfs.empty()){
                    int tx=bfs.front().first;
                    int ty=bfs.front().second;
                    bfs.pop();
                    for(int i=0;i<4;i++){
                        if(arr[tx+dx[i]][ty+dy[i]]){
                            bfs.push(make_pair(tx+dx[i],ty+dy[i]));
                            arr[tx+dx[i]][ty+dy[i]]=0;
                            for(int i=1;i<=n;i++){
            					for(int j=1;j<=m;j++) cout<<arr[i][j]<<' ';
            					cout<<'\n';
        					}
        					cout<<'\n';
                        } 
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
