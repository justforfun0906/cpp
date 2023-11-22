#include<stdio.h>
void hanoi(int n, char a, char b, char c){
    if(n==1){
        //printf("move disc %d from %c to %c\n", n, a, c);
        printf("%d\n", n);
    }else{
        hanoi(n-1,a,c,b);
        //printf("move disc %d from %c to %c\n", n, a, c);
        printf("%d\n", n);
        hanoi(n-1,b,a,c);
    }return;
}
int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
}