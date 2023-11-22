#include<stdio.h>
int main(){
    double a,b;
    char note;
    scanf("%lf %c %lf", &a, &note, &b);
    if(note == '+'){
        printf("%.3lf\n",a+b);
    }else if(note == '-'){
        printf("%.3lf\n",a-b);
    }else if(note == '*'){
        printf("%.3lf\n",a*b);
    }else{
        printf("%.3lf\n",a/b);
    }
}