#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node * new_node(int key){
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->left = NULL;
	p->right = NULL;
	p->data = key;
}

struct node * insert(struct node *node,int key){
	if(node == NULL){
		node = new_node(key);
		return node;
	}
	if(node->data < key)
		node->right = insert(node->right,key);
	else
		node->left = insert(node->left,key);
	return node;
}

void inorder(struct node *node){
	if(node == NULL)
		return ;
	inorder(node->left);
	printf("%d_",node->data);
	inorder(node->right);
}

void postorder(struct node *node){
	if(node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("%d_",node->data);
}

void preorder(struct node *node){
	if(node == NULL)
		return;
	printf("%d_",node->data);
	preorder(node->left);
	preorder(node->right);
}

int main(){
	int size,i,key;
	struct node *root = NULL;
	scanf("%d",&size);
	while(size){
		scanf("%d",&key);
		root = insert(root,key);
		size--;
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}
