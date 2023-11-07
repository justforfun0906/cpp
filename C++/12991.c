#include<stdio.h>
int h[20], c[20], visited[20]={0}, ans[20]={0},n,a1=0,a2=0;
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
int abss(int a,int b){
    if(a-b<0)return b-a;
    return a-b;
}
void jump(int s, int t,int cnt){
    //printf("now at %d, val=%d\n", s, ans[s]);
    if(s==t){
        if(ans[t]>a1){
            a1=ans[t];
            a2=cnt;
        }else if(ans[t]==a1){
            a2=max(a2,cnt);
        }
    }
    int color = c[s];
    visited[s]=1;
    if(s>1&&visited[s-1]==0){
        ans[s-1]= max(ans[s-1],ans[s]+abss(h[s-1],h[s]));
        jump(s-1,t,cnt+1);
    }
    if(s<n&&visited[s+1]==0){
        ans[s+1] = max(ans[s+1], ans[s]+abss(h[s+1],h[s]));
        jump(s+1,t,cnt+1);
    }
    for(int i=1;i<=n;i++){
        if(c[i]==color&&i!=s-1&&i!=s&&i!=s+1&&visited[i]==0){
            ans[i]= max(ans[i], ans[s]+(abss(i,s)*abss(h[i],h[s])));
            jump(i,t,cnt+1);
        }
    }
    visited[s]=0;
    ans[s]= 0;
}
int main(){
    int s, t;
    scanf("%d %d %d", &n, &s, &t);
    for(int i=1;i<=n;i++){
        scanf("%d", &h[i]);
    }for(int i=1;i<=n;i++){
        scanf("%d", &c[i]);
    }
    jump(s,t,0);
    printf("%d %d\n", a1, a2);
}