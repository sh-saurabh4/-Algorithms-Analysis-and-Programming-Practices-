#include<stdio.h>

int parent(int i){
	return i / 2;
}

int l_child(int i){
	return 2 * i;
}

int r_child(int i){
	return 2 * i + 1;
}

void swap(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void max_heapify(int a[],int size,int i){
	int max = i;
	int l = l_child(i);
	int r = r_child(i);
	if((l <= size) && (a[max] < a[l]))
		max = l;
	if((r <= size) && (a[max] < a[r]))
		max = r;
	if(max != i){
		swap(&a[i],&a[max]);
		max_heapify(a,size,max);
	}
}

void build_heap(int a[],int size){
	int i = parent(size);
	for(; i >= 1; i--){
		max_heapify(a,size,i);
	}
}

void increase_key(int a[],int i,int data){
	int c = i;
	int p = parent(c);
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


void heap_sort(int a[],int size){
	while(size){
		swap(&a[1],&a[size]);
		size--;
		max_heapify(a,size,1);
		
	}
}

void display(int a[],int size){
	int i;
	for(i = 1; i <= size; i++)
		printf("%d ",a[i]);
	printf("\n");
}
	
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t){
		scanf("%d",&n);
		int a[n];
		for(i = 1; i <= n; i++)
			scanf("%d",&a[i]);
		build_heap(a,n);
		
		heap_sort(a,n);
		display(a,n);
		t--;
	}
	return 0;
}
