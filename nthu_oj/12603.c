#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char s[200005];
    scanf("%s", s);
    int MIN = 1e9+5;
    int pos[200005];
    for(int i=0;i<n;i++) scanf("%d", &pos[i]);
    for(int i=0;i<n-1;i++){
        if(s[i]=='R'&&s[i+1]=='L'){
            if(MIN>(pos[i+1]-pos[i])/2) MIN = (pos[i+1]-pos[i])/2;
        }
    }
    if(MIN==1e9+5) printf("-1\n");
    else printf("%d\n", MIN);
}