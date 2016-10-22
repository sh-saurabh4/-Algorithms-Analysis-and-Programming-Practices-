#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};

struct node * insert(struct node * head, int n){
	struct node *p,*q;
	while(n){
		p =(struct node *)malloc(sizeof(struct node));
		p ->next = NULL;
		scanf("%d",&(p->data));

		if(head == NULL){
			q = head = p;
		}
		else{
			p->next = head;
			head = p;
		}
		n--;
	}
	return head;
}

int fun(struct node *head){
	int a=0,b=1,sum=0;
	struct node *p,*q,*r;
	p = head;
	q =NULL;
	r = p->next;
	while( p->next != NULL){
		if(p == head){
			sum += (a + (p->data))*(r->data);
		}
		else {
			sum += ((q->data)+(p->data))*(r->data);
		}
		q = p;
		p = r;
		r = r->next;
	}
	if(p == head){
		sum += (a+p->data)*b;
	}
	else
		sum += ((q->data)+ (p->data))*(b);
	
	return sum;
}



void prt_list(struct node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}
 int main()
{	struct node *head = NULL;
	int n;
	scanf("%d",&n);
	head = insert(head,n);
	prt_list(head);
	n = fun(head);
	printf("%d\n",n);
	return 0;


}




