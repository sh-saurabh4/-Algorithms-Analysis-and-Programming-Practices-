#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
};
void display(int *a,int n);
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

void inorder(struct node *node){
	if(node == NULL)
		return ;
	inorder(node->left);
	printf("%d_",node->data);
	inorder(node->right);
}

void print(struct node *node, int level,int *a){
	if(node == NULL)
		return ;
	
	a[level] = node->data;
	
	if(node->left == NULL && node->right == NULL){
		display(a,level);
		return;
	}
	if(node->left != NULL)
		print(node->left,level+1,a);
	if(node->right != NULL)
		print(node->right,level+1,a);
}

void display(int *a,int n){
	int i;
	for(i = 0; i <= n; i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main(){
	int i,n,key;
	struct node *root = NULL;
	int *a = (int *)malloc(sizeof(n));
	scanf("%d",&n);
	while(n){
		scanf("%d",&key);
		root = insert(root,key);
		n--;
	}
	//inorder(root);
	//printf("\n");
	print(root,0,a);
	return 0;
}


	
