
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int flag;
	struct node *next;
};
struct node * insert(struct node *head,int n){
	struct node *p,*q;
	while(n){
		p = (struct node *)malloc(sizeof(struct node ));
		p->next = NULL;
		scanf("%d",&(p->data));
		if(head == NULL)
			q = head = p;
		else{
			q->next = p;
			q = q->next;
		}
		n--;
	}
	p->next = head; // make circular
	return head;
}
void cshow(struct node *head){
	struct node *p = head;
	while(p->next != head){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}
void fun(struct node *head,int c){
	struct node *p = head;
	int a = c, i = 0;
	while(a){
		if(i % c == 0){
			
			if(p->flag == 1)break;
			printf("%d ",p->data);
			p->flag = 1;
		}
		if(p->next == head)
			a--;
		p = p->next;
		i++;
	}
}


int main()
{
	struct node *head=NULL;
	int n;
	scanf("%d",&n);
	head = insert(head,n);
	//cshow(head);
	fun(head,3);

	return 0;
}



