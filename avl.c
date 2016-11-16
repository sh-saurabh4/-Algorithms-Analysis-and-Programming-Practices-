#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
	int height;
};
int height(struct node *node){
	if(node == NULL)
		return 0;
	return node->height;
}
int max(int x,int y){
	return (x > y) ? x : y;
}
int balance_factor(struct node *node){
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}
struct node * left_rotate(struct node *node){
	struct node *p,*q;
	p = node->right;
	q = p->left;
	p->left = node;
	node->right = q;
	node->height = max(height(node->left),height(node->right))+1;
	p->height  = max(height(p->left),height(p->right))+1;
	return p;
}
struct node * right_rotate(struct node *node){
	struct node *p,*q;
	p = node->left;
	q = p->right;
	p->right = node;
	node->left = q;
	node->height = max(height(node->left),height(node->right))+1;
	p->height = max(height(p->left),height(p->right))+1;
	return p;
}
struct node * insert(struct node *node,int key){
	int bal,t1;
	if(node == NULL){
		node = (struct node *)malloc(sizeof(struct node));
		node->data = key;
		node->left = node->right = NULL;
		node->height = 1;
		return node;
	}
	if(node->data < key)
		node->right = insert(node->right,key);
	else
		node->left = insert(node->left,key);
	node->height = max(height(node->left),height(node->right))+1;
	bal = balance_factor(node);
	if(bal > 1){
		t1 = balance_factor(node->left);
		if(t1 >= 0)
			return right_rotate(node);
		else{
			node->left = left_rotate(node->left);
			return right_rotate(node);
		}
	}
	else if(bal < -1){
		t1 = balance_factor(node->right);
		if(t1 <= 0)
			return left_rotate(node);
		else{
			node->right = right_rotate(node->right);
			return left_rotate(node);
		}
	}
	return node;
}
void inorder(struct node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}
struct node * minvalue(struct node *node){
	if(node->left == NULL)
		return node;
	return minvalue(node->left);
}
struct node * delete(struct node *node,int key){
	struct node *t1,*t2;
	int bal;
	if(node == NULL)
		return NULL;
	else if(node->data < key)
		node->right = delete(node->right,key);
	else if(node->data > key)
		node->left = delete(node->left,key);
	else{
		if(node->left == NULL || node->right == NULL){
			t1 = node->left ? node->left : node->right;
			if(t1 == NULL){
				free(node);
				node = NULL;
			}
			else{
				*(node) = *(t1);
				free(t1);
				t1 = NULL;
			}
		}
		else{
			t1 = minvalue(node->right);
			node->data = t1->data;
			node->right = delete(node->right,t1->data);
		}
	}
	if(node == NULL)
		return node;
	node->height = max(height(node->left),height(node->right))+1;
	bal = balance_factor(node);
	if(bal > 1){
		if(balance_factor(node->left) >= 0)
			return right_rotate(node);
		else{
			node->left = left_rotate(node->left);
			return right_rotate(node);
		}
	}
	else if(bal < -1){
		if(balance_factor(node->right) <= 0)
			return left_rotate(node);
		else{
			node->right = right_rotate(node->right);
			return left_rotate(node);
		}
	}
	return node;
}
	
int main(){
	struct node *root = NULL;
	int n,i,key;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&key);
		root = insert(root,key);
	}
	inorder(root);
	scanf("%d",&key);
	while(key != -1){
		root = delete(root,key);
		inorder(root);
		scanf("%d",&key);
	}
	return 0;
}
