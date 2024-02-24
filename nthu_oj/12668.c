#include<stdio.h>
#include<string.h>
typedef struct node{
    struct node *prev, *next;
    int val;
}Node;
void solve(char* s,int n, Node* head){
    for(int i=0;i<n;i++){
        if(s[i]=='b'){
            
        }else if(s[i]=='r'){

        }else if(s[i]=='l'){

        }else{

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
        Node *head = (Node*)malloc(sizeof(Node));
        head->prev = NULL;
        head->next = NULL;
        solve(s, n, head);
        Node* now = head;
        while(now->next!=NULL){
            printf("%d", now->val);
            now = now->next;
        }
        if(now->prev!=NULL){
            printf("%d", now->val);
        }
    }
}