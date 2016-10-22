#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
void show(struct node *head);
struct node * insert(struct node *head,int n){
	struct node *p,*q;
	while(n){
		p = (struct node *)malloc(sizeof(struct node));
		p->next = NULL;
		scanf("%d",&(p->data));
		if(head == NULL){
			head = p;
			q = head;
		}
		else{
			q->next = p;
			q = q->next;
		}	
		n--;
	}
	return head;
}
struct node * insert_s(struct node *head,int v){
	struct node *p =(struct node *)malloc(sizeof(struct node));
	p->next = head;
	p->data = v;
	head = p;
	show(head);
	return head;
}

struct node * insert_e(struct node *s,int v){
	
	struct node *q,*p = (struct node *)malloc(sizeof(struct node*));
	p->next = NULL;
	p->data = v;
	q = s;
	while(q->next != NULL){
		q = q->next;
	}
	q->next = p;
	show(s);
	q->next = NULL;
	return s;
}

struct node * insert_k(struct node *head,int v,int k){
	struct node *p,*q;
	p = (struct node *)malloc(sizeof(struct node));
	p->next = NULL;
	p->data = v;
	q = head;
	while(k-2){
		q = q->next;
		k--;
	}
	p->next = q->next;
	q->next = p;
	show(head);
	return head;
}

void show(struct node *head){
	struct node *p;
	p = head;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");

}

struct node * del_s(struct node *head){
	head = head->next;
	show(head);
	return head;
}

struct node * del_e(struct node *head){
	struct node *p,*q;
	q = head;
	while(q->next->next != NULL){
		q = q->next;
	}
	p = q->next;
	q->next = NULL;
	show(head);
	q->next = p;
	return head;
}

struct node * del_k(struct node *head,int k){
	struct node *p,*q;
	p = head;
	while(k-2){
		p = p->next;
		k--;
	}
	q = p->next;
	p->next = p->next->next;
	show(head);
	q->next = p->next;
	p->next = q;
	return head;
}


int main(){
	int n,v,k;
	struct node *head = NULL;
	scanf("%d",&n);
	scanf("%d%d",&v,&k);

	head=insert(head,n);
	//show(head);	
	//insert_s(head,v);
	//show(head);
	
	//insert_e(head,v);
	//show(head);

	//insert_k(head,v,k);
	//show(head);
	
	del_s(head);
	del_e(head);
	del_k(head,k);


	return 0;
}











