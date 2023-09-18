#include<stdio.h>
#include<string.h>
int main(){
    char arr[5];
    scanf("%s", arr);
    for(int i=0;i<5;i++){
        int temp = arr[i]-'a';
        printf("%c", 'Z'-temp);
    }
    printf("\n");
}