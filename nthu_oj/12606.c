#include<stdio.h>
#include<stdlib.h>
int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
long long abss(long long a){
    if(a>0) return a;
    else return -a;
}
int main(){
    int N;
    scanf("%d",&N);
    long long ori;
    scanf("%lld",&ori);
    long long left = ori, right = ori;
    //printf("ori = %lld\n",ori);
    for(int i=0;i<N;i++){
        long long tmp;
        scanf("%lld",&tmp);
        //printf("tmp = %lld\n",tmp);
        if(tmp>right){
            right = tmp;
            //printf("right = %lld\n",right);
        }
        if(tmp<left){
            left = tmp;
            //printf("left = %lld\n",left);
        }
    }
    long long dis_left = abss((long long)ori-left), dis_right = abss((long long)ori-right);
    //printf("dis_left = %lld, dis_right = %lld\n",dis_left,dis_right);
    printf("%lld\n",2*(dis_left+dis_right));
}