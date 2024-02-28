#include<string.h>
typedef struct _Node {
    int serial, stu_id;
    char name[1001]; 
    struct _Node* next;
} Node;

void eFormSort(Node *head){
    Node *p = head;
    int n = 0;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    for (int i = 0; i < n; i++) {
        p = head;
        for (int j = 0; j < n - i - 1; j++) {
            if (p->stu_id > p->next->stu_id) {
                int serial = p->serial;
                int stu_id = p->stu_id;
                char name[1001];
                strcpy(name, p->name);
                p->serial = p->next->serial;
                p->stu_id = p->next->stu_id;
                strcpy(p->name, p->next->name);
                p->next->serial = serial;
                p->next->stu_id = stu_id;
                strcpy(p->next->name, name);
            }
            p = p->next;
        }
    }
}