#include<stdio.h>
#include<malloc.h>
struct node {
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
void preorder(struct node *root){
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main(){
	int i,n,key,*a;
	struct node *root = NULL;
	a = (int *)malloc(n * sizeof(int));
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(i = n-1; i>=0; i--)
		root = insert(root,a[i]);
	preorder(root);
	return 0;
}
		
