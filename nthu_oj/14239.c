#include<stdio.h>
#include<stdlib.h>
int N;
int direct_seafu[1010];
int student_cnt[1010];
int seafu_test(int a, int b){
    int temp = direct_seafu[a];
    while(temp!=0&&temp!=b){
        temp = direct_seafu[temp];
    }
    if(temp == b) return 0;
    temp = direct_seafu[b];
    while(temp!=0&&temp!=a){
        temp = direct_seafu[temp];
    }
    if(temp == a) return 1;
    return -1;
}
void solve(){
    int instruction;
    scanf("%d",&instruction);
    if(instruction == 1){
        int x;
        scanf("%d",&x);
        printf("%d\n",student_cnt[x]);
    }else{
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",seafu_test(a,b));
    }
}
int main(){
    scanf("%d",&N);
    for(int i=2;i<=N;i++){
        scanf("%d",&direct_seafu[i]);
        student_cnt[i] = 0;
    }
    direct_seafu[1] = 0; // FrankLee Orz
    student_cnt[1] = 0;
    for(int i=N;i>=2;i--){
        int temp = direct_seafu[i];
        while(temp!=0){
            student_cnt[temp] ++;
            temp = direct_seafu[temp];
        }
        student_cnt[temp]++;
    }
    int q;
    scanf("%d",&q);
    while(q--) solve();
}