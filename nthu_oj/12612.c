#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10005];
void mod(int l, int r, int k){
    k= k%(r-l+1);
    char mid[10005];
    strncpy(mid, s+l-1, r-l+1);
    //printf("%s %s %s\n", front, mid, back);
    for(int i=0;i<r-l+1;i++){
        s[(i+k)%(r-l+1)+l-1] = mid[i];
    }
}
int main(){
    scanf("%s", s);
    int m; scanf("%d", &m);
    while(m--){
        int l, r ,k; scanf("%d%d%d", &l, &r, &k);
        mod(l, r, k);
    }
    printf("%s\n", s);
}