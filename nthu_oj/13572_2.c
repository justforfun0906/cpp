#include<stdio.h>
#include<string.h>
int main(){
    char a[100005];
    scanf("%s",a);
    int q;
    scanf("%d\n", &q);
    while(q--){
        char c1, c2;
        c1 = getchar();
        char temp = getchar();
        c2 = getchar();
        temp = getchar();
        char *ptr = a;
        while(ptr!=NULL){
            ptr = strchr(a, c1);
            if(ptr){
                *ptr = c2;
            }
        }
    }
    printf("%s\n",a);
}