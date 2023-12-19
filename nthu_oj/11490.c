#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Cat{
    char *name;
    int occu_order;
    int age;
} cat;
char occu[10]= "enkwamdl";

cat* new_cat(){
    cat* temp= (cat*)malloc(sizeof(cat));
    temp->name = (char*)malloc(sizeof(char)*100);
    scanf(" %s",temp->name);
    //printf("Name = %s\n",temp->name);
    char o[20];
    scanf(" %s",o);
    for(int i=0;i<8;i++){
        if(o[0]==occu[i]){
            temp->occu_order = i;
            //printf("Occupation = %c\n", occu[i]);
            break;
        }
    }
    scanf("%d", &(temp->age));
    //printf("Age = %d\n", temp->age);
    return temp;
}
int cmp(const void *a, const void *b){
    cat *c1 = *(cat**)a;
    cat *c2 = *(cat**)b;
    if(c1->occu_order==c2->occu_order){
        if(c1->age>c2->age){
            return c1->occu_order==4?1:-1;
        }
        else if(c1->age<c2->age){
            return c1->occu_order==4?-1:1;
        }else if(c1->age==c2->age){
            return strcmp(c1->name,c2->name);
        }
    }else{
        return c1->occu_order-c2->occu_order;
    }
}
int main(){
    int n ,m;
    cat* c[10020];
    while(scanf("%d %d", &n, &m)!=EOF){
        for(int i=0;i<n;i++){
            c[i] = new_cat();
        }
        qsort(c,n,sizeof(cat*),cmp);
        for(int i=0;i<m&&i<n;i++){
            printf("%s\n", c[i]->name);
        }
        for(int i=0;i<n;i++){
            free(c[i]->name);
            free(c[i]);
        }
    }
}