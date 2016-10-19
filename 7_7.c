#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
int myindex=0;
struct node * new_node(int key){
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->data = key;
	p->left = p->right = NULL;
	return p;
}

int search(int inorder[],int key,int p , int q){
	int i;
	for(i = p; i <= q; i++){
		if(inorder[i] == key)
			return i;
	}
}

struct node * build(int inorder[],int preorder[],int p,int q){
	int r,key = preorder[myindex];
	myindex++;
	struct node * new = new_node(key);
	r = search(inorder,key,p,q);
	if(p != r)
		new->left = build(inorder,preorder,p,r-1);
	if(q != r)
		new->right = build(inorder,preorder,r+1,q);
	return new;
}
void postorder(struct node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d_",root->data);
	}
}

int main(){
	int inorder[100],preorder[100],n,i,key;
	struct node *root = NULL;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&inorder[i]);
	}
	for(i = 0; i < n; i++){
		scanf("%d",&preorder[i]);
	}
	root = build(inorder,preorder,0,n-1);
	postorder(root);
	return 0;
}
