#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

class ListNode
{
    friend class List_stack; //make List_stack a friend
    public:
        ListNode( const int &info ) //constructor
        : data( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor
    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};
List_stack::~List_stack(){
    ListNode* temp = this->tail;
    while(temp != this->head){
        temp = temp->prevPtr;
        delete temp->nextPtr;
    }
    delete this->head;
}
List_stack::List_stack(){
    this->head = new ListNode(0);
    this->tail = this->head;
}
void List_stack::push(const int &n){
    ListNode* newNode = new ListNode(n);
    this->tail->nextPtr = newNode;
    newNode->prevPtr = this->tail;
    this->tail = newNode;
}
void List_stack::pop(){
    if(this->tail == this->head){
        return;
    }
    ListNode* temp = this->tail;
    this->tail = this->tail->prevPtr;
    this->tail->nextPtr = NULL;
    delete temp;
}
void List_stack::print(){
    ListNode* temp = this->tail;
    while(temp != this->head){
        if(temp!=this->head->nextPtr)std::cout << temp->data << " ";
        else std::cout << temp->data;
        temp = temp->prevPtr;
    }
}
#endif // FUNCTION_H
