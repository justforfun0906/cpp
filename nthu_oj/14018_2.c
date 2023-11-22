#include <stdio.h>
char S[1000004];
void print(int p){
    for(int i = 0; i < p; i++) putchar(S[i]);
}
signed main(){
    int cnt = 0, z = 0, p = 0;
    char c;
    while(1){
        cnt = 0, c = getchar();
        if(c == EOF) break;
        if(c == '\n'){
            if(!z) print(p);
            else printf("Domo cannot crack this computer");
            putchar('\n');
            p = z = 0;
            continue;
        }
        if(z) continue;
        if(c < '0' || c > '9'){
            z = 1;
            continue;
        }
        while(c >= '0' && c <= '9') cnt = cnt * 10 + (c ^ 48), c = getchar();
        if(c == '\''){
            c = getchar();
            if(c < '0' || c > '9'){
                z = 1;
                continue;
            }
        }
        if(!cnt){
            z = 1;
            continue;
        }
        if(c == '\n'){
            p = 0;
            printf("Domo cannot crack this computer\n");
            continue;
        }
        while(cnt--) S[p++] = c;
        if(c >= '0' && c <= '9'){
            c = getchar();
            if(c != '\'') z = 1;
            if(c == '\n'){
                z = p = 0;
                printf("Domo cannot crack this computer\n");
            }
        }
    }
    return 0;
}