#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node * new_node(){
	return (struct node *)malloc(sizeof(struct node));
}

void insert(struct node ** a,int data,int n){
	int pos = data % n;
	struct node *p;
	if(a[pos] == NULL){
		p = new_node();
		p->next = NULL;
		p->data = data;
		a[pos] = p;
	}
	else {
		p = new_node();
		p->data = data;
		p->next = a[pos];
		a[pos] = p;
	}
}		
void show(struct node **a,int n){
	int i;
	struct node *p;
	for (i = 0; i < n; i++){
		printf("||->");
		p = a[i];
		while (p != NULL){
			printf("%d->",p->data);
			p = p->next;
		}
		printf("NULL\n");
	}
}

void search(struct node **a,int data,int n){
	int pos = data % n;
	struct node *p = a[pos];
	while(p != NULL){
		if(p -> data == data){
			printf("***********ITEM FOUND*********\n");
			break;
		}
		p = p->next;
	}
}

void delete(struct node **a , int data, int n){
	struct node *p,*q;
	int pos = data % n;
	p = q = a[pos];
	while (p != NULL){
		if(p->data == data){
			if(a[pos] == p){
				a[pos] = p->next;
				p = a[pos];
			}
			else{
			q->next = p->next;
			p = q->next;
			}
		}
		else {
			q = p;
			p = p->next;
		}
	}
	
}		 
	
		
int main(){
	struct node **a;
	int n,data,i;
	scanf("%d",&n);
	a = (struct node  **)malloc(n * sizeof(struct node *));
	for( i = 0; i < n; i++){
		a[i] = NULL;
	}
	while (1){
		scanf("%d",&data);
		insert(a,data,n);
		if(data == -1)
			break;
	}
	show(a,n);
	search(a,19,n);
	delete(a,19,n);
	show(a,n);

	return 0;
}
	

