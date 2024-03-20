#include<stdio.h>
#include<stdlib.h>
int N;
int direct_seafu[1010];
int find_distance(int a){//actually can be optimized by using a array to store the distance
    int distance = 0;
    if(direct_seafu[a]!=1){
        distance = find_distance(direct_seafu[a])+1;
    }
    else{
        distance = 1;
    }
    return distance;
}
int query(int a, int remain){
    if(remain!=0&&direct_seafu[a]==a){
        return -1;
    }else{
        if(remain!=0){
            return query(direct_seafu[a], remain-1);
        }else{
            return a;
        }
    }
}
int main(){
    scanf("%ds", &N);
    direct_seafu[1] = 1;//master LJH Orz
    for(int i=2;i<=N;i++){
        scanf("%d", &direct_seafu[i]);
    }
    for(int i=2;i<N;i++){
        printf("%d ", find_distance(i));
    }
    printf("%d\n", find_distance(N));
    int q; scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b));
    }
}