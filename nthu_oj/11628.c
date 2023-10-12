#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char a[n+5][n+5];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                a[i][j]=' ';
            }
        }
        int x=0, y=0;
        for(int i=0;i<n;i++){
            if(i%4==0){
                for(int j=0;j<n-i;j++){
                    y++;
                    a[x][y]='#';
                    //printf("%d %d\n", x, y);
                }
            }else if(i%4==1){
                for(int j=0;j<n-i;j++){
                    x++;
                    a[x][y]='#';
                    //printf("%d %d\n", x, y);
                }
            }else if(i%4==2){
                for(int j=0;j<n-i;j++){
                    y--;
                    a[x][y]='#';
                    //printf("%d %d\n", x, y);
                }
            }else{
                for(int j=0;j<n-i;j++){
                    x--;
                    a[x][y]='#';
                    //printf("%d %d\n", x, y);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++) printf("%c", a[i][j]);
            printf("\n");
        }
    }
}