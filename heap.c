#include<stdio.h>
#include<limits.h>

void heapify(int a[], int i, int h_size);
void swap(int *, int *);
void increase_key(int a[], int i,int h_size);

int  insert_new(int a[], int value, int h_size){
	a[h_size + 1] = INT_MIN;
	increase_key(a,h_size + 1,value);
	return (h_size + 1);
}


void increase_key(int a[], int i, int value){
	int p;
	if(a[i] >= value )
		printf("Value inserted is less\n");
	p = i / 2 ;
	while( i >= 2){
		a[i] = value;
		if(a[i] > a[p]){
			swap(&a[i],&a[p]);
			i = p;
			p = p / 2;
		}
		else
			break;
	}
}


void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void build_heap(int a[], int h_size){
	int i = h_size / 2;
	for(; i >=1; i--){
		heapify(a,i,h_size);
	}
}



void heapify(int a[],int i, int h_size){
	int max = i;
	
	if((2 * i <= h_size) && (a[2 * i] > a[i]))
			max = 2 * i;
	if((2 * i + 1 <= h_size) && (a[2 * i + 1] > a[max]))
			max = 2 * i + 1;
	if(max != i){
		swap(&a[i],&a[max]);
		heapify(a,max,h_size);
	}
}

void show(int a[], int h_size){
	int i;
	for(i = 1; i <= h_size; i++)
		printf("%d ",a[i]);
	printf("\n");
}


void insert(int a[], int h_size){
	int i;
	for(i = 1; i <= h_size; i++)
		scanf("%d",&a[i]);
}


int main(){
	int h_size;
	scanf("%d",&h_size);
	int a[h_size + 100];
	insert(a,h_size);
	show(a,h_size);
	build_heap(a,h_size);
	show(a,h_size);
	increase_key(a,4,100);
	show(a,h_size);
	h_size = insert_new(a,500,h_size);
	show(a,h_size);
	return 0;
}




	

