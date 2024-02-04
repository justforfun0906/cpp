#include<stdio.h>
int main(){
    int len, n;
    scanf("%d %d", &len, &n);
    char s[len+5];
    scanf("%s", s);
    int alph[26];
    for(int i=0;i<26;i++){
        alph[i] = 'a'+i;
    }
    for(int i=0;i<n;i++){
        char a, b;
        scanf(" %c %c", &a, &b);
        for(int j=0;j<26;j++){
            if(alph[j]==a){
                alph[j] = b;
            }else if(alph[j]==b){
                alph[j] = a;
            }
        }
    }
    for(int i=0;i<len;i++){
        printf("%c", alph[s[i]-'a']);
    }
    printf("\n");
}