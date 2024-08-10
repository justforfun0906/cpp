#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data, bf, height, size;
    Node *left, *right, *parent;
    void update(){
        int left_height = (left == nullptr) ? 0 : left->height;
        int right_height = (right == nullptr) ? 0 : right->height;
        height = max(left_height, right_height) + 1;
        size = 1;
        if(left != nullptr){
            size += left->size;
        }
        if(right != nullptr){
            size += right->size;
        }
        bf = left_height - right_height;
    }
    Node(){};
    Node(int _data): data(_data), bf(0), height(1), size(1), left(nullptr), right(nullptr), parent(nullptr){};
}*root;

Node* find_min(Node *x){
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

void transplant(Node *u, Node *v){
    if(u->parent == nullptr){
        //u is the root
        root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    if(v != nullptr){
        v->parent = u->parent;
    }
}

void right_rotate(Node* x){
    Node* left_child = x->left;

    transplant(x, left_child);
    x->left = left_child->right;
    if(left_child->right != nullptr){
        left_child->right->parent = x;
    }
    left_child->right = x;
    x->parent = left_child;

    x->update();
    left_child->update();
}

void left_rotate(Node* x){
    Node* right_child = x->right;

    transplant(x, right_child);
    x->right = right_child->left;
    if(right_child->left != nullptr){
        right_child->left->parent = x;
    }
    right_child->left = x;
    x->parent = right_child;

    x->update();
    right_child->update();
}

void insert(Node *&x, Node *object){
    //use reference to pointer to change the value of pointer
    if(x == nullptr){
        x = object;
        //cout<<x->data<<' ';
        return;
    }
    if(x->data == object->data){
        return;
    }
    if(x->data > object->data){
        if(x->left == nullptr){
            x->left = object;
            object->parent = x;
        }else{
            insert(x->left, object);
        }
    } else{
        if(x->right == nullptr){
            x->right = object;
            object->parent = x;
        }else{
            insert(x->right, object);
        }
    }
    x->update();
    if(x->bf == 2){//left is heavy
        Node* left_child = x->left;
        if(left_child->bf == 1){//LL
            right_rotate(x);
        }else{
            left_rotate(left_child);
            right_rotate(x);
        }
    }else if(x->bf == -2){//right is heavy
        Node* right_child = x->right;
        if(right_child->bf == -1){//RR
            left_rotate(x);
        }else{
            right_rotate(right_child);
            left_rotate(x);
        }
    }
}

Node* search(Node *x, int key){
    if(x == nullptr){
        return nullptr;
    }else if(x->data == key){
        return x;
    }else if(x->data > key){
        return search(x->left, key);
    }else{
        return search(x->right, key);
    }
}

void delete_node(Node* x, int key){
    if(x == nullptr){
        return;
    }
    if(x->data > key){
        delete_node(x->left, key);
    }else if(x->data < key){
        delete_node(x->right, key);
    }else{
        //x is the node to be deleted
        if(x->left == nullptr && x->right == nullptr){
            transplant(x, nullptr);
            return;
        }else if(x->left == nullptr){
            transplant(x, x->right);
            return;
        }else if(x->right == nullptr){
            transplant(x, x->left);
            return;
        }else{
            Node* y = find_min(x->right);
            delete_node(x->right, y->data);
            x->data = y->data;
        }
    }
    x->update();
    if(x->bf == 2){//left is heavy
        Node* left_child = x->left;
        //important: check left_child->bf >= 0
        if(left_child->bf >= 0){//LL
            right_rotate(x);
        }else{
            left_rotate(left_child);
            right_rotate(x);
        }
    }else if(x->bf == -2){//right is heavy
        Node* right_child = x->right;
        if(right_child->bf <=0){//RR
            left_rotate(x);
        }else{
            right_rotate(right_child);
            left_rotate(x);
        }
    }
}
int order(Node* x, int k) {
    if (x == nullptr) {
        return -1; // Error value, k is out of bounds
    }

    int left_size = (x->left != nullptr) ? x->left->size : 0;

    if (k == left_size + 1) {
        return x->data;
    } else if (k <= left_size) {
        return order(x->left, k);
    } else {
        return order(x->right, k - (left_size + 1));
    }
}
void output(Node* x){
    if(x == nullptr){
        return;
    }
    output(x->left);
    cout<<x->data<<' ';
    output(x->right);
}
int main(){
    int q;
    cin>>q;
    root = nullptr;
    while(q--){
        string ins;
        int x;
        cin>>ins>>x;
        if(ins == "INS"){
            Node* object = new Node(x);
            insert(root, object);
        }else if(ins == "DEL"){
            delete_node(root, x);
        }else{
            if(root==nullptr||root->size < x){
                cout<<-1<<'\n';
            }else{
                // print k-th smallest element
                cout<<order(root, x)<<'\n';
            }
        }
    }
    return 0;
}