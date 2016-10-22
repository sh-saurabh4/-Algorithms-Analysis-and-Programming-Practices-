#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *left,*right;
};

struct node * insert(struct node * node,int key){
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

int equal(struct node *root1, struct node *root2){
	if(root1 == NULL && root2 == NULL)
		return 1;
	else if(root1 != NULL && root2 != NULL && (root1->data == root2->data)){
		return (equal(root1->left,root2->left) && equal(root1->right,root2->right));
	}
	else
		return 0;
}

void inorder(struct node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	printf("%d_",node->data);
	inorder(node->right);
}

int main(){
	struct node *root1 = NULL, *root2 = NULL;
	int n,i,key,t;
	scanf("%d%d",&t,&n);
	while(t){
		//scanf("%d",&n);
		root1 = root2 = NULL;
		for(i = 0; i < n; i++){
			scanf("%d",&key);
			root1 = insert(root1,key);
		}
		//inorder(root1);
		for(i = 0; i < n; i++){
			scanf("%d",&key);
			root2 = insert(root2,key);
		}
		//inorder(root2);
		if(equal(root1,root2))
			printf("y\n");
		else
			printf("n\n");
		t--;
	}
	return 0;
}

