#include<string.h>
#include<stdio.h>
int main(){
    char a[500];
    int n;
    scanf("%d %s\n",&n, a);
    //char dmp; dmp = getchar();
    printf("%d\n%s\n",n,a);
    for(int i=0;i<n;i++){
        char input[500];
        fgets(input,500,stdin);
        char *p;
        char *d=":,.?! ";
        p = strtok(input,d);
        while(p!=NULL){
            printf("%d\n",p-input);
            p = strtok(NULL, d);
        }
    }
}