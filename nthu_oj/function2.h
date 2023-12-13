#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char *guestName;
    int groupSize;
    int arriveTime;
    int diningTime;
} Guest;

typedef struct {
    int tableSize;
    int leaveTime;
    Guest *guest;
} Table;

Table* createTable(){
    Table *temp = malloc(sizeof(Table));
    int s;
    scanf("%d",&s);
    temp->guest=NULL;
    temp->leaveTime=0;
    temp->tableSize=s;
    return temp;
}
Guest* createGuest(){
    Guest *guest = malloc(sizeof(Guest));
    guest->guestName = malloc(100*sizeof(char));
    scanf("%s",guest->guestName);
    int s,a,d;
    scanf("%d %d %d",&s, &a, &d);
    guest->groupSize = s;
    guest->arriveTime = a;
    guest->diningTime = d;
    return guest;
}
Guest* checkLeave(Table **table, int tableCount, int currentTime){
    for(int i=0;i<tableCount;i++){
        if(table[i]->leaveTime==currentTime&&table[i]->guest!=NULL){
            Guest* temp = malloc(sizeof(Guest));
            temp = table[i]->guest;
            table[i]->guest=NULL;
            return temp;
        }
    }
    return NULL;
}
int assignTable(Table **table, int tableCount, int currentTime, Guest *guest){
    int flag = 0;
    for(int i=0;i<tableCount;i++){
        if(table[i]->guest==NULL&&table[i]->tableSize>=guest->groupSize){
            table[i]->guest=guest;
            table[i]->leaveTime=currentTime+(guest->diningTime);
            flag = 1;
            break;
        }
    }
    return flag;
}

#endif