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