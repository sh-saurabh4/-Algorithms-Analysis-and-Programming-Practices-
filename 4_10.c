#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node * insert(struct node * head,int n){
	struct node *p,*q;
	while(n){
		p = (struct node *)malloc(sizeof(struct node));
		p->next = NULL;
		p->prev = NULL;
		scanf("%d",&(p->data));
		if(head == NULL){
			q = head = p;
		}
		else{
			q->next = p;
			p->prev = q;
			q = q->next;
		}
		n--;


	}
	return head;

}

struct node * rev(struct node *head){
	struct node *p,*q=NULL;
	p = head;
	while(p->next != NULL){

		p = p->next;
	}
	head = p;
	return head;
}
		

void show(struct node * head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->prev;
	}printf("\n");
}



int main()
{
	struct node *head = NULL;
	int n;
	scanf("%d",&n);
	head = insert(head,n);
	//show(head);
	head = rev(head);
	show(head);
	return 0;
}










