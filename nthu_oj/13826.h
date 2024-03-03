#include<string.h>
typedef struct _Node {
    int serial, stu_id;
    char name[1001]; 
    struct _Node* next;
} Node;

void eFormSort(Node *head){
    Node *p = head;
    Node *p_pre = NULL;
    int now = 1;
    while(p != NULL){
        if(p->serial != now){
            Node *q = p;
            Node *q_pre = p_pre;
            while(q->serial != now){
                q_pre = q;
                q = q->next;
            }
            q_pre->next = q->next;
            q->next = p;
            p_pre->next = q;
            p = q;
            //printf("swap %d %d\n", p->serial, q->serial);
        }
        p_pre = p;
        p = p->next;
        now++;
    }
}