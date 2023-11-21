#include<stdio.h>
#include<stdlib.h>
int p[105][105];
int visit[105][105]={0};
int roller_x = 1, roller_y = 1, roller_dir;
int snake_x = 1, snake_y = 1, snake_dir = 1;
int target_x, target_y;
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n,m,s;
int check_bound(int x,int y){
    return(x>=1 && x<=n && y>=1 && y<=m);
}
int search(int i){
    int x = roller_x, y = roller_y;
    while((x!=snake_x || y!= snake_y)&&check_bound(x,y)){
        x+=dx[i];
        y+=dy[i];
    }
    return (x==snake_x && y==snake_y);
}
void teleport(){
    int tx = 1, ty = 1, mn = 1e6;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            if(!visit[i][j] && (abs(p[i][j]-p[roller_x][roller_y])< mn || (abs(p[i][j]-p[roller_x][roller_y])==mn && p[i][j]<p[tx][ty]))){
                tx = i;
                ty = j;
                mn = abs(p[i][j]-p[roller_x][roller_y]);
            }
        }
    }
    roller_x = tx;
    roller_y = ty;
    s--;
}
void snake_move(){
    if(check_bound(snake_x, snake_y+dy[snake_dir])==0) snake_dir = (snake_dir+1) % 2;//wtf this is genius;
    snake_y += dy[snake_dir];
}
int main(){
    scanf("%d %d %d", &n, &m, &s);
    int mn = 1e6, mx = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &p[i][j]);
            if(p[i][j]>mx){
                mx = p[i][j];
                roller_x = i;
                roller_y = j;
            }
            if(p[i][j]<mn){
                mn = p[i][j];
                snake_x = i;
                snake_y = j;
            }
        }
    }
    int state = 0;// 0 = emit light 1 = teleport 2 = move
    while(s!=0 && (roller_x!=snake_x || roller_y!=snake_y)){
        visit[roller_x][roller_y]=1;
        if(state == 0){
            for(int i=0;i<8;i++){
                if(search(i)){
                    target_x = snake_x;
                    target_y = snake_y;
                    roller_dir = i;
                    state = 2;
                    break;
                }
            }
            if(state == 0) state = 1;
        }else if(state == 1){
            teleport();
            snake_move();
            state = 0;
        }else{
            if(roller_x==target_x && roller_y == target_y) state = 0;
            else{
                roller_x += dx[roller_dir], roller_y += dy[roller_dir];
                s--;
                snake_move();
            }
        }
    }
    printf("%d\n", s);
    if(roller_x==snake_x && roller_y == snake_y){
        printf("Gotcha!\n");
    }else{
        printf("NO Snake QQ~\n");
    }
}