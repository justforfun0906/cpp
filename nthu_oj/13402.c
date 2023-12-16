#include<stdio.h>
int board[16][16];
int check(int n, int m){
    int flag = 1;
    //printf("now:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-1>=0){
                if(board[i][j]!=board[i-1][j]) flag = 0;
            }
            if(j<m-1){
                if(board[i][j]!=board[i][j+1]) flag = 0;
            }
            if(flag != 1)break;
           // printf("%d",board[i][j]);
        }
        //printf("\n");
    }
    return flag;
}
void mod(int n,int m,int i, int j){
    board[i][j]=(board[i][j]+1)%2;
    if(i-1>=0) board[i-1][j]=(board[i-1][j]+1)%2;
    if(i+1<n) board[i+1][j]=(board[i+1][j]+1)%2;
    if(j-1>=0) board[i][j-1]=(board[i][j-1]+1)%2;
    if(j+1<m) board[i][j+1]=(board[i][j+1]+1)%2;
}
int flip(int n,int m, int last_i, int last_j,int cnt){//
    int result = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=last_i&&j!=last_j){
                mod(n,m,i,j);
                if(check(n,m)){
                    result = cnt;
                    return result;
                }else{
                    result = flip(n,m,i,j,cnt+1);
                }
                mod(n,m,i,j);
            }
        }
    }
    return result;
}
int main(){
    int n, m;
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            scanf(" %c",&temp);
            if(temp=='b') board[i][j]=0;
            else board[i][j]=1;
        }
    }
    int result = flip(n,m,-1,-1,0);
    if(result != -1){
        printf("%d\n", result);
    }else{
        printf("opps\n");
    }
}
