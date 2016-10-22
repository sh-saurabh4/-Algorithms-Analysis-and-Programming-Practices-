#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
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
	return head;
}
int max(struct node *head){
	int max = head->data;
	while(head != NULL){
		if(head->data > max)
			max = head->data;
		head = head->next;
	}
	return max;
}
			
int min(struct node *head){
	int min = head->data;
	while(head != NULL){
		if(head->data < min)
			min = head->data;
		head = head->next;
	}
	return min;
}

int main()
{
	struct node *head=NULL;
	int n;
	scanf("%d",&n);
	head = insert(head,n);
	printf("MAX=%d\n",max(head));
	printf("MIN=%d\n",min(head));
	return 0;
}



