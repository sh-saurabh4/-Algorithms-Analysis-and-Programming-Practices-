#include<stdio.h>
#include<limits.h>

int parent(int i){
	return i / 2;
}

int left_child(int i){
	return 2 * i;
}

int right_child(int i){
	return 2 * i + 1;
}

void swap(int *p, int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
} 

void increase_key(int a[],int i,int data){
	int p,c = i;
	a[i] = data;
	p = parent(c);
	while(p >= 1){
		if(a[p] < a[c]){
			swap(&a[p],&a[c]);
			c = p;
			p = parent(c);
		}
		else
			break;
	}
}
void max_heapify(int a[],int size,int i){
	int max = i;
	int l = left_child(i);
	int r = right_child(i);
	if((l <= size) && (a[l] > a[max]))
		max = l;
	if((r <= size ) && (a[r] > a[max]))
		max = r;
	if(max != i){
		swap(&a[i],&a[max]);
		max_heapify(a,size,max);
	}
}

int insert(int a[],int size,int data){
	size = size + 1;
	a[size] = INT_MIN;
	increase_key(a,size,data);
	printf("inserted\n");
	return size;
}

int delete(int a[],int size,int data){
	int count = 0;
	int i;
	for(i = 1; i <= size; i++){
		if(a[i] == data){
			increase_key(a,i,INT_MAX);
			swap(&a[1],&a[size]);
			size--;
			max_heapify(a,size,1);
			count++;
			i = 0;
			
		}
	}
	if(count == 0)
		printf("%d not found\n",data);
	else
		printf("deleted\n");
	return size;
}

void display(int a[], int size){
	int i;
	for(i = 1; i <=size ; i++)
		printf("%d ",a[i]);
	printf("\n");
}
		
int main(){
	int i,data,size = 0,a[100000];
	scanf("%d",&i);
	while(i - 4 ){
		switch(i){
			
			case 1:
				scanf("%d",&data);
				size = insert(a,size,data);
				break;
			case 2:
				scanf("%d",&data);
				size = delete(a,size,data);
				break;
			case 3:
				display(a,size);
				break;
			}
		scanf("%d",&i);
	}
	return 0;
}



