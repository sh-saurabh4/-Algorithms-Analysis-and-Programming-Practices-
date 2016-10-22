
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
struct node * del(struct node *head, int d){
	struct node *p,*q = NULL;
	p = head;
	
		while((p != NULL) && (p->data != d)){
			q = p;
			p = p->next;
		}
		if(p == NULL)
			printf("NO NOT EXISTS\n");
		else{
			if(head->data == d)
				head = head->next;
			else{
				q -> next = p->next;
				if(p->next != NULL)
					p->next->prev = q;
			}
		}
	
	return head;
}
			

void show(struct node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head = head->next;
	}printf("\n");

}

int main(){
	int n,d;
	struct node *head = NULL;
	scanf("%d",&n);
	head = insert(head,n);
	scanf("%d",&d);
	head = del(head,d);
	show(head);
	return 0;
}



