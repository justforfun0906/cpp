#include<stdio.h>
int x,y,dx,dy,dirX;
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
int map[105][105]={0};
int cnt = 0, num = 0;
int n,m;
void move(){
    //printf("now at %d %d with val= %d\n", x, y, map[x][y]);
    cnt+=map[x][y];
    if(map[x][y]!=0)num++;
    int val = map[x][y];
    map[x][y]=0;
    if(val<=dirX&&x+dx<=n&&x+dx>=1&&y+dy<=m&&y+dy>=1){
        x+=dx;
        y+=dy;
        move();
    }
}
void scan(){
    int max = 0;
    dx = 0, dy = 0;
    for(int i=0;i<4;i++){
        if(map[x+xx[i]][y+yy[i]]>max){
            dx=xx[i];
            dy=yy[i];
            max = map[x+dx][y+dy];
        }
    }
    dirX = map[x+dx][y+dy];
    //printf("dx=%d, dy=%d, going to %d %d with val= %d\n",dx,dy,x+dx,y+dy,map[x+dx][y+dy]);
}
int main(){
    scanf("%d %d", &n, &m);
    int max = -1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &map[i][j]);
        }
    }
    x = 1, y = 1;
    dx = 1;
    dy = 1;
    for(int i=0;i<4;i++){
        if(map[x+xx[i]][y+yy[i]]>map[x+dx][y+dy]){
            dx = xx[i];
            dy = yy[i];
        }
    }
    dirX = map[x+dx][y+dy];
    while(!(dx==0&&dy==0)){
        move();
        scan();
    }
    printf("%d\n", cnt);
    if(num>=n*m){
        printf("Road Roller Da!!\n");
    }
}