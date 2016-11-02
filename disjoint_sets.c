#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *parent;
};
struct set{
	struct node *root;
};
struct items{
	int data;
	struct node *location;
};
struct node * make_set(int data);
struct items * insert(int size){
	struct items * ptr = (struct items *)malloc(size * sizeof(struct items));
	int i,key;
	for(i = 0; i < size; i++){
		scanf("%d",&key);
		ptr[i].data = key;
		ptr[i].location = make_set(key);
	}
	return ptr;
}
struct node * make_set(int data){
	struct node * ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->parent = ptr;
	return ptr;
}
struct node * find(struct items *ptr,int size,int key){
	int i;
	struct node *p;
	for(i = 0; i < size; i++){
		if(ptr[i].data == key){
			p = ptr[i].location;
			break;
		}
	}
	while(p->parent != p)
		p = p->parent;
	return p;
}
struct node *myunion(int key1,int key2,int size,struct set *sets,struct items * items){
	struct node * node1 = find(items,size,key1);
	struct node * node2 = find(items,size,key2);
	int i;
	struct set *tree1,*tree2;
	for(i = 0; i < size; i++){
		if(sets[i].root == node1)
			tree1 = &(sets[i]);
		if(sets[i].root == node2)
			tree2 = &(sets[i]);
	}
	node1->parent = node2;
	tree1->root = NULL;
	return node2;
}
void print(struct set * trees,int size){
	while(size){
		if(trees[size-1].root != NULL)
			printf("%d ",trees[size-1].root->data);
		size--;
	}
}
int main(){
	int i,n,no_sets;
	struct node *p;
	struct items * allnodes = NULL;
	struct set * sets = NULL;
	scanf("%d",&n);
	no_sets = n;
	allnodes = insert(n);
	sets = (struct set *)malloc(n * sizeof(struct set));
	for(i = 0; i < n; i++){
		sets[i].root = allnodes[i].location;
	}
	print(sets,n);
	p = find(allnodes,n,3);	
	printf("\n%d",p->data);
	myunion(1,4,n,sets,allnodes);
	print(sets,n);
	printf("\n");
	myunion(2,4,n,sets,allnodes);
	print(sets,n);
	return 0;
}
	 
