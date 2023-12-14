#include<stdio.h>
int board[16][16];
int check(int n, int m){
    int flag = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i-1][j]!=board[i][j]) flag = 0;
            if(j<m-1&&board[i][j]!=board[i][j+1]) flag =0;
            if(flag != 1)break;
        }
    }
    return flag;
}
int flip(int n,int m, int cnt){//

}
int main(){
    int n, int m;
    
}
