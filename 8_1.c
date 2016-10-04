#include<stdio.h>

int parent(int i){
	if(i % 2 == 0)
		return i / 2;
	else
		return (i / 2) - 1;
}

int left_child(int i){
	return (2 * i + 1);
}

int right_child(int i){
	return (2 * i + 2);
}

int swap(int *p, int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void min_heapify(int a[],int size,int i){
	int min = i, last = size - 1;
	int l = left_child(i);
	int r = right_child(i);
	
	if((l <= last) && (a[i] > a[l]))
		min = l;
	if((r <= last) && (a[min] > a[r]))
		min = r;
	if(min != i){
		swap(&a[i],&a[min]);
		min_heapify(a,size,min);
	}
}

void build(int a[], int size){
	int last = size - 1;
	int i = parent(last);
	
	for(; i >= 0; i--)
		min_heapify(a,size,i);
	
}

void display(int a[],int size){
	int i;
	for(i = 0; i < size; i++)
		printf("%d ",a[i]);
	printf("\n");
}

int  delete(int a[],int size){
	swap(&a[0],&a[size - 1]);
	size = size - 1;
	min_heapify(a,size,0);
	return size;
}

int main(){
	int t,n,k,i;
	scanf("%d",&t);
	while(t){
		scanf("%d%d",&n,&k);
		int a[n];
		for(i = 0; i < n; i++)
			scanf("%d",&a[i]);
		build(a,n);
		display(a,n);
		
		for(i = 0; i < k; i++){
			n = delete(a,n);
		}

		display(a,n);

		t--;
		//printf("hello");
	}
	return 0;
}

