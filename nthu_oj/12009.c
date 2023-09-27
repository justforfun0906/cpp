#include<stdio.h>
int main(){
    char str[4];
    int n;
    scanf("%s %d", str, &n);
    n = n%26;
    for(int i=0;i<3;i++){
        int temp = str[i]-'A';
        temp += n;
        temp %= 26;
        if(temp<0) temp = 26 + temp;
        char ans = 'A'+temp;
        printf("%c", ans);
    }
    printf("\n");
}