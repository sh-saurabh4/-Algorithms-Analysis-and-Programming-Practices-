#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node * insert(struct node *head,int n){
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

int small(struct node *head){
	int min = head->data;
	while(head != NULL){
		if(min > head->data)
			min = head->data;
		head = head->next;
	}
	return min;
}

void show(struct node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head = head->next;
	}printf("\n");

}

int main(){
	int n;
	struct node *head = NULL;
	scanf("%d",&n);
	head = insert(head,n);
	show(head);
	printf("%d\n",small(head));
	return 0;
}



