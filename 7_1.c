#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left ,*right;
};
struct node * new_node(int key){
	struct node *p = (struct node *)malloc(sizeof(struct node ));
	p->right = NULL;
	p->data = key;
	p->left = NULL;
	return p;
}

struct node * insert(struct node *root, int key){
	if(root == NULL)
		return new_node(key);
	if(root->data < key)
		root->right = insert(root->right,key);
	else
		root->left = insert(root->left,key);
	return root;
}

void inorder(struct node *root){
	if(root == NULL)
		return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);	
}
struct node * search(struct node *root,int key){
	if(root == NULL || root->data == key)
		return root;
	if(root->data > key)
		return search(root->left,key);
	else
		return search(root->right,key);
}

int main(){
	int size,key,k;
	struct node *root = NULL,*node;
	scanf("%d",&size);

	while(size){
		scanf("%d",&key);
		root = insert(root,key);
		size--;
	}
	//inorder(root);
	scanf("%d",&k);
	while(k){
		scanf("%d",&key);
		node = search(root,key);
		if(node == NULL)
			printf("n\n");
		else	
			printf("y\n");
		k--;
	}
	
	return 0;
}
