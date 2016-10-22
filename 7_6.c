
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
int find(struct node *node,int sum){
	if(node == NULL)
		return sum;
	if(node->left == NULL && node->right == NULL)
		sum += node->data;
	sum = find(node->left,sum);
	sum = find(node->right,sum);
	return sum;
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
