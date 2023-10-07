#include<stdio.h>
#include<string.h>
int max(int a, int b){
    if(a>b)return a;
    else return b;
}
int m[20][20]={0};
int check1(int target,int n){//right
    int ans =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][j]==target){
                int temp =0;
                for(int k=j;k<=j+5&&k<20;k++){
                    if(m[i][k]==target)temp++;
                    else break;
                }
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}
int check2(int target,int n){//down syndrome
    int ans =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][j]==target){
                int temp =0;
                for(int k=j;k<=i+5&&k<20;k++){
                    if(m[k][j]==target)temp++;
                    else{
                        temp = 0;
                        break;
                    }
                }
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}
int check3(int target,int n){//down right
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp = 0;
            if(m[i][j]==target){
                for(int k=i;k<=i+5&&k<20;k++){
                    for(int l=i;l<=j+5&&l<20;l++){
                        if(m[k][l]==target){
                            temp++;
                        }else{
                            temp = 0;
                            break;
                        }
                    }
                }
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}
int check4(int target, int n){//down left
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp = 0;
            if(m[i][j]==target){
                for(int k=i;k<=i+5&&k<20;k++){
                    for(int l=i;l>=j-5&&l>=0;l--){
                        if(m[k][l]==target){
                            temp++;
                        }else{
                            temp = 0;
                            break;
                        }
                    }
                }
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}
int main(){
    int n,x,y;
    scanf("%d", &n);
    int L_max=0, T_max=0;//L first
    int now = 1;
    while(scanf("%d %d", &x, &y)){
        if(now%2==1){//L's turn
            m[x][y]=1;
            L_max=max(L_max, max(check1(1,n),max(check2(1,n),max(check3(1,n),check4(1,n)))));
            if(L_max==5)break;
        }else{//T's turn
            m[x][y]=2;
            T_max=max(T_max, max(check1(2,n),max(check2(2,n),max(check3(2,n),check4(2,n)))));
            if(T_max==5)break;
        }
        now++;
    }
    if(L_max==5){
        int step = (now+1)/2;
        printf("LSC wins at the %dth step", now);
    }else if(T_max==5){
        int step = now/2;
        printf("TSC wins at the %dth step", now);
    }else{
        printf("There's no winner.");
    }
}