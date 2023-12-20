#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int x;
    struct Node* next;
} node;
node Head;
node* head= &Head;
void pop(){
    if(head->next!=NULL) head->next = head->next->next;
}
void push(int x){
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = (node*)malloc(sizeof(node));
    temp = temp ->next;
    temp->x = x;
    temp->next = NULL;
}
void reverse(){
    node* current = head;
    if(current->next!=NULL){//not empty
        //printf("in\n");
        current = current->next; //first element;
        node* next_node = NULL;
        node* prev = NULL;
        while(current!=NULL){// current is not the last node
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        head ->next = prev;
        printf("first element is %d\n", head->next->x);
    }
}
void print(){
    node* temp = head;
    if(temp->next!=NULL){
        temp = temp->next;
        printf("%d",temp->x);
    }
    temp = temp->next;
    while(temp!=NULL){
        printf(" -> %d", temp->x);
        temp = temp->next;
    }
    printf("\n");
}
int main(){ 
    char request[100];
    head->x = 1e6;
    head->next = NULL;
    while(scanf("%s",request)!=EOF){
        if(strcmp(request,"push")==0){
            int x;
            scanf("%d",&x);
            push(x);
        }else if(strcmp(request,"pop")==0){
            pop();
        }else if(strcmp(request,"reverse")==0){
            reverse();
        }else if(strcmp(request,"print")==0){
            print();
        }
    }
}