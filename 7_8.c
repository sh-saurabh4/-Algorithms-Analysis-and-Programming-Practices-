#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node * new_node(int key){
	struct node *p = (struct node*)malloc(sizeof(struct node));
	p->data = key;
	p->left = p->right = NULL;
	return p;
}
	
struct node * build(int *postorder,int p,int q){
	struct node *node = new_node(postorder[q]);
	int r = (p+q)/2;
	if(p != q){
		node->left = build(postorder,p,r-1);
		node->right = build(postorder,r,q-1);
	}
	return node;
}
	
void inorder(struct node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main(){
	struct node *root = NULL;
	int n,i;
	int *postorder;
	scanf("%d",&n);
	postorder = (int *)malloc(n*sizeof(int));
	for(i = 0; i < n ; i++){
		scanf("%d",&postorder[i]);
	}
	root = build(postorder,0,n-1);
	inorder(root);
	return 0;
}
