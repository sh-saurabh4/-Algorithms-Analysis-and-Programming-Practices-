#include<stdio.h>

int parent(int i){
	return i / 2;
}

int left_child(int i){
	return 2 * i;
}

int right_child(int i){
	return (2 * i + 1);
}

int value(int i){
	if(i < 0)
		return (-1 * i);
	else
		return i;
}

void swap(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void max_heapify(int a[],int size,int i){
	int max = i;
	int l = left_child(i);
	int r = right_child(i);

	if( (l <= size) && (value(a[l]) > value(a[max])) )
		max = l;
	if( (r <= size) && ( value(a[r]) > value(a[max]) ) )
		max = r;
	if(i != max){
		swap(&a[i],&a[max]);
		max_heapify(a,size,max);
	}
}

void build(int a[],int size){
	int i = parent(size);
	for(;i >= 1; i--){
		max_heapify(a,size,i);
	}
}

void sort(int a[],int size){
	while(size){
		swap(&a[1],&a[size]);
		size--;
		max_heapify(a,size,1);
	}
}

void display(int a[],int size){
	int i;
	for(i = 1; i <= size; i++)
		printf("%d\n",a[i]);
}

int main(){
	int n,i;
	scanf("%d",&n);
	int a[n+1];
	for(i = 1; i <= n ;i++)
		scanf("%d",&a[i]);
	
	build(a,n);
	sort(a,n);
	display(a,n);
	return 0;
}






