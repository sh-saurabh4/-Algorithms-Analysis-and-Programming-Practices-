#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};

int sum_even(struct node *head){
	struct node *p,*q;
	int c = 1,sum = 0;
	p = head;
	while(p != NULL){
		if(c == 0){
			sum += p->data;
			c = 1;
		}
		else
			c = 0;

		p = p->next;
	}
	return sum;
}

struct node * insert(struct node *head, int n){
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
	return head;
}

int main()
{
	struct node *head = NULL;
	int n;
	scanf("%d",&n);
	head = insert(head,n);
	printf("SUM OF EVEN POS=%d\n",sum_even(head));
	return 0;
}




















