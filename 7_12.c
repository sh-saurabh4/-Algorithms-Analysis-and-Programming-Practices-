#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
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
struct node * search(struct node * node, int key){
	if(node == NULL || node->data == key)
		return node;
	if(node->data < key)
		return search(node->right,key);
	else
		return search(node->left,key);
}
struct node * inorder_successor(struct node * node,int key){
	struct node *ptr;
	ptr = search(node,key);
	if(ptr == NULL)
		return NULL;
	if(ptr->right == NULL)
		return NULL;
	ptr = ptr->right;
	while(ptr->left != NULL)
		ptr = ptr->left;
	return ptr;
}
struct node * inorder_predecessor(struct node * node,int key){
	struct node *ptr;
	ptr = search(node,key);
	if(ptr == NULL)
		return NULL;
	if(ptr->left == NULL)
		return NULL;
	ptr = ptr->left;
	while(ptr->right != NULL)
		ptr = ptr->right;
	return ptr;
}
void print(struct node * ptr){
	if(ptr != NULL){
		printf("%d\n",ptr->data);
		return; 
	}
	printf("***ENTER THE VALID DATA*****\n");
}
void show(struct node * node){
	if(node == NULL)
		return;
	show(node->left);
	printf("%d+",node->data);
	show(node->right);
}
int main(){
	int n,key;
	struct node * root = NULL,*ptr;
	scanf("%d",&n);
	while(n){
		scanf("%d",&key);
		root = insert(root,key);
		n--;
	}
	
	scanf("%d",&key);
	ptr = inorder_successor(root,key);
	print(ptr);
	ptr = inorder_predecessor(root,key);
	print(ptr);
	return 0;
}









