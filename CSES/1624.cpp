#include<iostream>
using namespace std;
int g[10][10];
int ans = 0;
int check_queen(int x,int y){
    for(int i=0;i<8;i++){
        if(g[x][i]==2) return 0;
        if(g[i][y]==2) return 0;
    }
    for(int i=0;i<8;i++){
        if(x+i<8 && y+i<8 && g[x+i][y+i]==2) return 0;
        if(x-i>=0 && y-i>=0 && g[x-i][y-i]==2) return 0;
        if(x+i<8 && y-i>=0 && g[x+i][y-i]==2) return 0;
        if(x-i>=0 && y+i<8 && g[x-i][y+i]==2) return 0;
    }
    return 1;
}
void dfs(int now_q){
    if(now_q==8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        if(g[now_q][i]==0 && check_queen(now_q,i)){
            g[now_q][i]=2;
            dfs(now_q+1);
            g[now_q][i]=0;
        }
    }
    return;
}
int main(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char t;
            cin>>t;
            if(t=='*') g[i][j]=1;//blocked
            else g[i][j]=0;//not blocked
        }
    }
    dfs(0);
    cout<<ans;
}