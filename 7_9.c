#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node * insert(struct node * node, int key){
	if(node == NULL){
		node = (struct node *)malloc(sizeof(struct node));
		node->left = node->right = NULL;
		node->data = key;
		return node;
	}
	if(node->data < key)
		node->right = insert(node->right,key);
	else
		node->left = insert(node->left,key);
	return node;
}
struct node * delete_all(struct node * node){
	if(node == NULL)
		return NULL;
	node->left = delete_all(node->left);
	node->right = delete_all(node->right);
	printf("%d ",node->data);
	return NULL;
}
void inorder(struct node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}
int main(){
	struct node *root = NULL;
	int key,n;
	scanf("%d",&n);
	while(n){
		scanf("%d",&key);
		root = insert(root,key);
		n--;
	}
	inorder(root);
	printf("\n");
	root = delete_all(root);
	if(root == NULL)
		printf("\nBST DELETED\n");
	return 0;
}
