#include<stdio.h>
int main(){
    int temp;
    scanf("%d", &temp);
    int a[3], b[3];
    a[0] = temp / 1000;
    b[0] = temp % 1000;
    a[1] = temp / 100;
    b[1] = temp % 100;
    a[2] = temp / 10;
    b[2] = temp % 10;
    for(int i=0;i<3;i++){
        int ans = a[i]*b[i];
        if(i<2) printf("%d ", ans);
        else printf("%d", ans);
    }
    printf("\n");
}