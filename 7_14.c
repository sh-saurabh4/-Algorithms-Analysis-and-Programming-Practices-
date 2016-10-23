#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node * left,*right;
};
struct node * insert(struct node * node, int key){
	if(node == NULL){
		node = (struct node *)malloc(sizeof(struct node));
		node->data = key;
		node->left = node->right = NULL;
		return node;
	}
	if(node->data < key)
		node->right = insert(node->right,key);
	else
		node->left = insert(node->left,key);
	return node;
}
struct node * delete_terminals(struct node *node){
	if(node == NULL)
		return NULL;
	if(node->left == NULL && node->right == NULL)
		return NULL;
	node->left = delete_terminals(node->left);
	node->right = delete_terminals(node->right);
	return node;
}
void inorder(struct node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}
int main(){
	struct node * root = NULL;
	int n,key;
	scanf("%d",&n);
	while(n){
		scanf("%d",&key);
		root = insert(root,key);
		n--;
	}
	inorder(root);
	printf("\n");
	root = delete_terminals(root);
	inorder(root);
	printf("\n");
	return 0;
}
