#include<iostream>
#include<algorithm>
#include<assert.h>
using namespace std;

struct Node {
	int key, bf, h, sz; // sz: subtree size
	Node *l, *r, *pa;

	void update(){
		int lh = (l ? l->h : -1);
		int rh = (r ? r->h : -1);
		int lsz = (l ? l->sz : 0);
		int rsz = (r ? r->sz : 0);
		sz = 1 + lsz + rsz;
		h = max(lh, rh) + 1;
		bf = lh - rh;
	}

	Node(){}
	Node(int _key): key(_key), bf(0), h(0), sz(1), pa(NULL), l(NULL), r(NULL) {}
}*root;

Node* find_min(Node *x){
	while(x->l)
		x = x->l;
	return x;
}

void transplant(Node *x, Node *y){
	if(!x->pa)
		root = y;
	else if(x->pa->l == x)
		x->pa->l = y;
	else
		x->pa->r = y;
	if(y)
		y->pa = x->pa;
}

void right_rotate(Node *x){
	Node *left_child = x->l;

	transplant(x, left_child);

	x->l = left_child->r;
	if(left_child->r)
		left_child->r->pa = x;

	left_child->r = x;
	x->pa = left_child;

	x->update();
	left_child->update();
}

void left_rotate(Node *x){
	Node *right_child = x->r;

	transplant(x, right_child);

	x->r = right_child->l;
	if(right_child->l)
		right_child->l->pa = x;

	right_child->l = x;
	x->pa = right_child;

	x->update();
	right_child->update();
}

void insert(Node *&x, Node *z){
	if(x == NULL){
		x = z;
		return;
	}
	if(z->key == x->key)
		return;
	if(x->key < z->key){
		if(x->r)
			insert(x->r, z);
		else
			x->r = z, z->pa = x;
	}
	else{
		if(x->l)
			insert(x->l, z);
		else
			x->l = z, z->pa = x;
	}
	x->update();
	if(x->bf == 2){
		if(x->l->bf == 1)
			right_rotate(x);
		else if(x->l->bf == -1)
			left_rotate(x->l), right_rotate(x);
	}
	else if(x->bf == -2){
		if(x->r->bf == -1)
			left_rotate(x);
		else if(x->r->bf == 1)
			right_rotate(x->r), left_rotate(x);
	}
	assert(abs(x->bf) < 2);
}

void deletion(Node *x, int key){
	if(x == NULL)
		return;
	if(key < x->key)
		deletion(x->l, key);
	else if(key > x->key)
		deletion(x->r, key);
	else{
		if(!(x->l) && !(x->r)){
			transplant(x, NULL);
			return;
		}
		else if(!(x->l))
			transplant(x, x->r);
		else if(!(x->r))
			transplant(x, x->l);
		else{
			Node* y = find_min(x->r);
			deletion(x->r, y->key);
			x->key = y->key;
		}
	}
	x->update();
	if(x->bf == 2){
		if(x->l->bf >= 0)
			right_rotate(x);
		else if(x->l->bf == -1)
			left_rotate(x->l), right_rotate(x);
	}
	else if(x->bf == -2){
		if(x->r->bf <= 0)
			left_rotate(x);
		else if(x->r->bf == 1)
			right_rotate(x->r), left_rotate(x);
	}
	assert(abs(x->bf) < 2);
}

int order_of_key(Node *x, int key){
	if(x == NULL)
		return 0;
	if(x->key <= key)
		return 1 + (x->l ? x->l->sz : 0) + order_of_key(x->r, key);
	return order_of_key(x->l, key);
}

int main(){
	int q;
	root = NULL;
	cin >> q;
	while(q--){
		string s;
		int k;
		cin >> s >> k;
		if(s == "INS")
			insert(root, new Node(k));
		else if(s == "DEL")
			deletion(root, k);
		else
			cout << order_of_key(root, k) << '\n';
	}
}