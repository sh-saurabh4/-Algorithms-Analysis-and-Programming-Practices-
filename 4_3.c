#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	};
struct node* insort(struct node *head, int n){
	struct node *p = NULL,*q = NULL,*r = NULL;
	while(n){
		p = (struct node *)malloc(sizeof(struct node));
		scanf("%d",&(p->data));
		p->next = NULL;

		if(head == NULL)
			head = p;
		else{	
			r = NULL;
			q = head;
			while(q->next != NULL && (q->data > p->data)){
				r = q;
				q = q->next;
			}
			if(q->next == NULL && (q->data > p->data)){		//insert at tail
				q->next = p;
			}
			else{
				if( q == head){		//insert at head
					p->next = q;
					head = p;
				}
				else{			//middle insert
					r->next = p;
					p->next = q;
				}
			}
		}
	n--;
	}
	return head;
}

				
void show(struct node *head){
	struct node *p = head;
	while(p != NULL){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void reverse(struct node *head){
	if(head->next != NULL)
		reverse(head->next);
	printf("<-%d",head->data);
}


int main()
{
	int n;
	struct node *head = NULL;
	scanf("%d",&n);
	
	head = insort(head,n);
	show(head);

	printf("NULL");
	reverse(head);
	printf("\n");
	
	return 0;
}
	
