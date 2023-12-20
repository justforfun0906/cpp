#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} Node;
void Pop(Node** ptr_head){
    if(*ptr_head!=NULL){//non empty
        Node *next = (*ptr_head)->next, *now = *ptr_head;
        *ptr_head = next;
        free(now);
    }
}
void Push(Node** ptr_head, int x){
    if(*ptr_head == NULL){
        *ptr_head = (Node*)malloc(sizeof(Node));
        (*ptr_head)->data = x;
        (*ptr_head)->next = NULL;
    }
    else{
        Node* next = *ptr_head;
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = x;
        new_node->next = next;
        (*ptr_head) = new_node;
    }
}
void Reverse_List(Node** ptr_head){
    Node *prev = NULL, *current = *ptr_head, *next = NULL;
    if(current!=NULL){//not empty
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *ptr_head = prev;
    }
}
#endif