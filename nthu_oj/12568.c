#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int x;
    struct Node* next;
} node;
node* head;
void push(int x){
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = (node*)malloc(sizeof(node));
    temp->next->x = x;
    temp->next->next = NULL;
}
int main(){
    char request[100];
    head->next = NULL;
    while(scanf("%s",request)!=EOF){
        if(strcmp(request,"push")==0){
            int x;
            scanf("%d",&x);
            push(x);
        }else if(strcmp(request,"pop")==0){
            node* temp = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            printf("%d\n",temp->next->x);
            free(temp->next);
            temp->next = NULL;
        }else if(strcmp(request,"reverse")==0){
            node* temp = head;
            node* temp2 = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = NULL;
            temp2->next = head->next;
            head->next = temp2;
        }else if(strcmp(request,"print")==0){
            node* temp = head;
            while(temp->next!=NULL){
                printf("%d ",temp->next->x);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}