#include<stdio.h>
#include<string.h>
int max(int a, int b){
    if(a>b)return a;
    else return b;
}
int m[20][20];
int check1(int target){//right
    int ans =0;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            if(m[i][j]==target){
                int temp =0;
                for(int k=j;k<j+5&&k<=15;k++){
                    if(m[i][k]==target)temp++;
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
int check2(int target){//down syndrome
    int ans =0;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            if(m[i][j]==target){
                int temp =0;
                for(int k=i;k<i+5&&k<=15;k++){
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
int check3(int target){//down right
    int ans = 0;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            int temp = 0;
            if(m[i][j]==target){
                for(int k=i, l=j; k<i+5&&k<=15&&l<j+5&&l<=15; k++, l++){
                    if(m[k][l]==target){
                        temp++;
                    }else{
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
int check4(int target){//down left
    int ans = 0;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            int temp = 0;
            if(m[i][j]==target){
                for(int k=i, l=j;k<i+5&&k<=15&&l>j-5&&l>=1;k++,l--){
                    if(m[k][l]==target){
                        temp++;
                    }else{
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
int ultimate_check(int target){
    int ans = 0;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            int temp = 0;
            if(m[i][j]==target){
                for(int k=j;k<=15&&k<j+5;k++){
                    if(m[i][k]==target){
                        temp++;
                    }else{
                        temp =0;
                    }
                }
                ans = max(ans, temp);
                temp = 0;
                for(int k=i;k<=15&&k<i+5;k++){
                    if(m[k][j]==target){
                        temp++;
                    }else{
                        temp =0;
                    }
                }
                ans = max(ans, temp);
                temp = 0;
                for(int k=i,l=j;k<i+5&&k<=15&&l<j+5&&l<=15;k++, l++){
                    if(m[k][l]==target){
                        temp++;
                    }else{
                        temp = 0;
                    }
                }
                ans=max(ans, temp);
                temp =0;
                for(int k=i, l=j;k<i+5&&k<=15&&l>j-5&&l>0;k++, l--){
                    if(m[k][l]==target){
                        temp++;
                    }else{
                        temp =0;
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
    int found_step;
    for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) m[i][j] = 0;
    while(now <= n){
        scanf("%d %d", &x, &y);
        if(now%2==1){//L's turn
            m[x][y]=1;
            //L_max=max(L_max, max(check1(1),max(check2(1),max(check3(1),check4(1)))));
            L_max=max(L_max,ultimate_check(1));
            if(L_max>=5){
                found_step= now;
                break;
            }
        }else{//T's turn
            m[x][y]=2;
            //T_max=max(T_max, max(check1(2),max(check2(2),max(check3(2),check4(2)))));
            T_max=max(T_max,ultimate_check(2));
            if(T_max>=5){
                found_step=now;
                break;
            }
        }
        now++;
    }
    if(L_max>=5){
        printf("LSC wins at the %dth step.\n", found_step);
    }else if(T_max>=5){
        printf("TSC wins at the %dth step.\n", found_step);
    }else{
        printf("There's no winner.\n");
    }
}