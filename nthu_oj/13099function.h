#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct _Item {
    char* name;
    int price;
    int discount;
    int quality;
} Item;

Item* CreateList(int N){
    Item *list = (Item*)malloc(N*sizeof(Item));
    return list;
}
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality ){
    L[idx].name = (char*)malloc(100*sizeof(char));
    strcpy(L[idx].name,name);
    L[idx].price = price;
    L[idx].discount = discount;
    L[idx].quality = quality;
}

void DeleteList(Item* L, int N){
    for(int i=0;i<N;i++){
        free(L[i].name);
    }
    free(L);
}

int price_cmp( const void* lhs, const void* rhs ){
    int a = ((Item*)lhs)->price - ((Item*)lhs)->discount;
    int b = ((Item*)rhs)->price - ((Item*)rhs)->discount;
    if(a>b)return 1;
    else if(a==b)return 0;
    else return -1;
}
int discount_cmp( const void* lhs, const void* rhs ){
    int a = ((Item*)lhs)->discount;
    int b = ((Item*)rhs)->discount;
    if(a<b)return 1;
    else if(a==b)return 0;
    else return -1;
}
int quality_cmp( const void* lhs, const void* rhs ){
    int a = ((Item*)lhs)->quality;
    int b = ((Item*)rhs)->quality;
    if(a<b)return 1;
    else if(a==b)return 0;
    else return -1;
}

#endif