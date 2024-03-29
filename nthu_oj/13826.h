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
    while(p != NULL){//until reach the end
        if(p->serial != now){//if the serial number of p is not equal to the value that we are finding
            Node *q = p;
            Node *q_pre = p_pre;
            while(q->serial != now){//finding target node
                q_pre = q;
                q = q->next;
            }
            q_pre->next = q->next;//move q to the front of p
            q->next = p;
            p_pre->next = q;
            p = q;//important
            //printf("swap %d %d\n", p->serial, q->serial);
        }
        p_pre = p;
        p = p->next;
        now++;//move to the next node
    }
}