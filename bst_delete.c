#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right,*parent;
};
struct node * insert(struct node * node, int key,struct node *parent){
	if(node == NULL){
		node = (struct node *)malloc(sizeof(struct node));
		node->data = key;
		node->left = node->right = NULL;
		node->parent = parent;
		return node;
	}
	if(node->data < key)
		node->right = insert(node->right,key,node);
	else
		node->left = insert(node->left,key,node);
	return node;
}
void inorder(struct node * node){
	if(node == NULL)
		return;
	inorder(node->left);
	printf("%d_",node->data);
	inorder(node->right);
}
struct node * search(struct node *node, int key){
	if(node == NULL || node->data == key){
		return node;
	}
	if(node->data < key)
		return search(node->right,key);
	else
		return search(node->left,key);
}
struct node * minvalue(struct node *node){
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}
struct node * delete(struct node * node, int key){
	struct node *ptr = search(node,key),*p,*q;
	int min,temp;
	if(ptr == NULL){
		//printf("hello%d\n",ptr->data);
		return node;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		p = ptr->parent;printf("hello");
		if(p->left == ptr){
			p->left == NULL;
			return ptr;
		}
		else{
			p->right == NULL;
			return ptr;
		}
	}
	else if(ptr->left == NULL || ptr->right == NULL){//scanf("%d",&min);
		if(ptr->left == NULL){
			p = ptr->parent;
			if(p->left == ptr){
				p->left = ptr->right;
				ptr->right = NULL;
				return ptr;
			}
			else{
				p->right = ptr->right;
				ptr->right = NULL;
				return ptr;
			}
		}
		else{
			p = ptr->parent;
			if(p->left == ptr){
				p->left = ptr->left;
				ptr->left = NULL;
				return ptr;
			}
			else{
				p->right = ptr->left;
				ptr->left = NULL;
				return ptr;
			}
		}
	}
	else{
		q = minvalue(ptr->right);
		temp = ptr->data;
		ptr->data = q->data;
		q->data = temp;
		p = q->parent;
		if(q->left == NULL)
			p->right = NULL;
		else
			p->left = q->left;
		return q;
	}
}




int main(){
	struct node *root = NULL,*p;
	int n,key,i;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&key);
		root = insert(root,key,NULL);
	}
	scanf("%d",&key);
	inorder(root);
	printf("\n");
	p = delete(root,key);
	inorder(root);
	printf("\n");
	return 0;
}

