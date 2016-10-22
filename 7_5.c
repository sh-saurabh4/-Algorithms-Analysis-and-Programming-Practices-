#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *left,*right;
};
struct node *insert(struct node *node,int key){
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
int find(struct node *node,int count){
	if(node == NULL)
		return count;
	if(node->left == NULL && node->right == NULL)
		count++;
	count = find(node->left,count);
	count = find(node->right,count);
	return count;
}

int main(){
	struct node *root = NULL;
	int n,i,key,count = 0;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&key);
		root = insert(root,key);
	}
	count = find(root,count);
	printf("%d\n",count);
	return 0;
}
