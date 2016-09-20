#include<stdio.h>
#include<malloc.h>

int * copy(int *a, int size);
void show(int *a, int cap, int size){
	int i;
	printf("capacity = %d; size = %d; elements = ",cap,size);
	for (i = 0; i < size; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
		

int * copy(int *a, int size){
	int i;
	int *b = (int *)malloc(2*size*sizeof(int));
	
	for ( i = 0; i < size; i++){
		b[i] = a[i];
	}
	return b;
}	



int * insert(int *a, int cap, int size, int n){
	
	while(size != n){
		if(cap == 0){
			a = (int *)malloc(sizeof(int));
			scanf("%d",&a[0]);
			size = 1;
			cap = 1;
			show(a,cap,size);
		}
		else {
			if(size == cap){
				a = copy(a,size);
				cap = 2 * cap;
				scanf("%d",&a[size]);
				size++;
				show(a,cap,size);
			}
			else{
				scanf("%d",&a[size]);
				size++;
				show(a,cap,size);
			}
		}
	}
	return a;
}




int main(){
	int n,size = 0,cap = 0,*arr;
	scanf("%d",&n);
	arr = insert(arr,cap,size,n);
	//show(arr,n);
	return 0;
}	
