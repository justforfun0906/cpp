#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num){
    if((*head)->next == NULL){//empty
        (*head)->next = (Node*)malloc(sizeof(Node));
        (*head)->next->next = NULL;
        (*head)->next->idx = num;
        (*back) = (*head)->next;
    }else{
        Node* next = (*head)->next;
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->next = next ;
        new_node->idx = num;
        (*head)->next = new_node; 
    }
}
void AddBack(Node** head, Node** back, int num){
    if((*head)->next == NULL){//empty -> same as AddFront
        (*head)->next = (Node*)malloc(sizeof(Node));
        (*head)->next->next = NULL;
        (*head)->next->idx = num;
        (*back) = (*head)->next;
    }else{
        (*back)->next = (Node*)malloc(sizeof(Node));
        (*back)->next->next = NULL;
        (*back)->next->idx = num;
        (*back) = (*back)->next;
    }
}
void DeleteFront(Node** head, Node** back){
    if((*head)->next!=NULL){//non empty
        Node* original = (*head)->next;
        (*head)->next = original -> next ;
        if((*head)->next==NULL) *back = *head;
        free(original);
    }
}
void Delete(Node** head, Node** back, int num){
    if((*head)->next!=NULL){
        Node* now = (*head)->next;
        Node* prev = *head;
        while(now!=NULL){
            if(now->idx == num){//delete node pointed by "now"
                prev->next = now->next;
                if(now->next==NULL){
                    *back = prev;
                }
                free(now);
            }else{//"prev" point to "now", "now" point to next node
                prev = now;
            }
            now = prev->next;
        }
    }
}
void Swap(Node** head, Node** back){
    if((*head)->next!=NULL){//non empty
        *back = (*head)->next;
        Node *prev = NULL, *current = (*head)->next, *next = NULL;
        while(current!=NULL){
            next  = current ->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        (*head)->next = prev;
    }
}