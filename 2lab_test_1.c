#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node * insert(struct node * head,int n){
	struct node *p;
	while(n){
		p = (struct node *)malloc(sizeof(struct node));
		p -> next = NULL;
		scanf("%d",&(p->data));
		if(head == NULL){
			head = p;
		}
		else{
			p->next = head;
			head = p;
		}
		n--;
	}
	return head;
}
void show(struct node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

struct node * split(struct node *head){
	struct node *p,*q;
 	p = head;
	while(p != NULL){
		q = (struct node *)malloc(sizeof(struct node));
		q->next = NULL;
		if(p->data % 2 == 0){
			q->data = p->data / 2;
			p->data = p->data / 2;
		}
		else{
			q->data = p->data / 2;
			p->data = p->data / 2 + 1;
		}
		q->next = p->next;
		p->next = q;
		p = q->next;
	}
	return head;
}

int main(){
	struct node *head = NULL;
	int n;
	scanf("%d",&n);
	head = insert(head,n);
	show(head);
	head = split(head);
	show(head);
	return 0;
}

	
