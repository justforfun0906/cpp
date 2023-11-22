#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[1000005];
int main(){
    int now = 0;
    char temp = getchar();
    while(temp!='\n'){
        a[now++]=temp;
        temp = getchar();
    }
    int q;
    scanf("%d", &q);
    temp = getchar();
    int chart[26];
    for(int i=0;i<26;i++){
        chart[i]=i;
    }
    while(q--){
        char t1, t2;
        t1 = getchar();
        temp = getchar();
        t2 = getchar();
        temp = getchar();
        int a = t1-'a', b = t2-'a';
        //printf("%d %d\n", a, b);
        for(int i=0;i<26;i++){
            if(chart[i]==a) chart[i]=b;
        }
    }
    for(int i=0;i<now;i++){
        printf("%c", 'a'+chart[a[i]-'a']);
    }
    printf("\n");
}