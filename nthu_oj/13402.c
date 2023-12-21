#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int graph[20][20],N,M;//1_base
int check(){
    int stat = graph[1][1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(graph[i][j]!=stat){
                return 0;
            }
        }
    }
    return 1;
}
void flip(int id){
    int x = id/M + 1;
    int y = id%M + 1;
    graph[x][y]^=1;
    graph[x+1][y]^=1;
    graph[x-1][y]^=1;
    graph[x][y+1]^=1;
    graph[x][y-1]^=1;
}
void flip_all(int st){
    for(int id=0;id<(N*M);id++){
        if(st&(1<<id)) flip(id);
    }
}
int one_cnt(int st){
    int cnt = 0;
    for(int i=0;i<N*M;i++){
        if(st&(1<<(N*M)))cnt++;
    }
    return cnt;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++){
            for(int j = 1; j <= M ;j++){
                char temp;
                scanf(" %c", &temp);
                if(temp == 'b') graph[i][j] = 1;
                else graph[i][j] = 0;
            }
        }
        int MIN = 7122;
        for(int st = 0 ; st<(1<<(N*M));st++){
            int ocnt = one_cnt(st);
            if(ocnt>MIN) continue;
            else{
                flip_all(st);
                if(check()){
                    if(ocnt<MIN)MIN = ocnt;
                }
                flip_all(st);
            }
        }
        if(MIN!=7122)printf("%d\n",MIN);
        else printf("oops\n");
    }
}