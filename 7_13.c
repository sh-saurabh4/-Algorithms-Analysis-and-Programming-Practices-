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
int ancestors(struct node * node,int key){
	if(node == NULL)
		return 0;
	if(node->data == key)
		return 1;
	if(ancestors(node->left,key) || ancestors(node->right,key)){
		printf("%d\n",node->data);
		return 1;
	}
	return 0;
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
	scanf("%d",&key);
	ancestors(root,key);
	return 0;
}
