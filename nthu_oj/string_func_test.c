#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char a[500], b[500],c[500];
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    strcpy(b,a);
    strcat(a,c);
    printf("%s\n%s\n", b, a);
}