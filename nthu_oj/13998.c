#include<stdio.h>
int main(){
    char chart[50];
    scanf("%s", chart);
    char in[5];
    scanf("%s", in);
    for(int i=0;i<3;i++){
        char temp = in[i];
        if(temp>='A'&&temp<='Z'){
            int ind = temp - 'A';
            printf("%c", chart[ind]);
        }else{
            int ind = temp - 'a';
            char fake = chart[ind];
            ind = fake - 'A';
            printf("%c", 'a'+ind);
        }
    }
    printf("\n");
}