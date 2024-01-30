#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data);
Node* createList();
void deleteNode(Node ** nd, int data) {
    int cnt = 1;
    Node *temp = *nd, *prev;
    if (temp != NULL && cnt == data) {
        *nd = temp->next;
        free(temp);
        return;
    }//if deleting the first node
    while (temp != NULL && cnt != data) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
Node* createList(){
    Node *head, *now;
    head = (Node*)malloc(sizeof(Node));
    now = head;
    head->next = NULL;
    int data;
    scanf("%d", &data);
    while (data!=-1) {
        now->data = data;
        scanf("%d", &data);
        if(data==-1){
            now->next = NULL;
            break;
        }
        else{
            now->next = (Node*)malloc(sizeof(Node));
            now = now->next;
        }
    }
    return head;
}