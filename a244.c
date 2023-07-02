#include<stdio.h>
int main(){
    int t,a;
    long long b,c;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %lld %lld", &a, &b, &c);
        switch (a)
        {
        case 1:
            printf("%lld \n",b+c);
            break;
        case 2:
            printf("%lld \n",b-c);
            break;
        case 3:
            printf("%lld \n",b*c);
            break;
        case 4:
            printf("%lld \n",b/c);
            break;
        }
    }
}