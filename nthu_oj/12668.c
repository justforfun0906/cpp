#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    struct node *prev, *next;
    int val;
}Node;
void solve(char* s,int n, Node* head, Node* tail){
    Node* now = head;
    //printf("s = %s\n", s);
    for(int i=0;i<n;i++){
        if(s[i]=='B'){//backspace
            Node *del = now;
            now = now->prev;
            now->next = del->next;
            now->next->prev = now;
            free(del);
        }else if(s[i]=='R'){//move cursor to right
            now = now->next;
        }else if(s[i]=='L'){//move cursor to left
            now = now->prev;
        }else{//insert new node before cursor
            Node* new = (Node*)malloc(sizeof(Node));
            new->val = s[i];
            if(now->next!=NULL){
                new->next = now->next;
                new->next->prev = new;
            }
            new->prev = now;
            now->next = new;
            now = new;
        }
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char s[n+5];
        scanf("%s", s);
        Node *head = (Node*)malloc(sizeof(Node)), *tail = (Node*)malloc(sizeof(Node));
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
        head->val = -1;
        tail->val = -1;
        solve(s, n, head, tail);
        Node* now = head->next;
        while(now!=tail){
            printf("%c", now->val);
            Node* del = now;
            now = now->next;
            free(del);
        }
        printf("\n");
    }
}