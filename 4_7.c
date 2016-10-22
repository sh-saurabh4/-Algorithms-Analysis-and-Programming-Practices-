#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node * insert(struct node *s,int n){
	struct node *p,*q;
	while(n){
		p = (struct node *)malloc(sizeof(struct node));
		p -> next = NULL;
		p -> prev = NULL;
		scanf("%d",&(p->data));
		if(s == NULL){
			q = s = p;
		}
		else{
			q->next = p;
			p->prev = q;
			q = q->next;
		}
		
		n--;
	}
	return s;
}

void show(struct node *s){
	while(s != NULL){
		printf("%d ",s->data);
		s = s->next;
	}
}

int main()
{	
	int n;
	struct node *head = NULL;
	scanf("%d",&n);
	head = insert(head,n);
	show(head);
	return 0;
}































