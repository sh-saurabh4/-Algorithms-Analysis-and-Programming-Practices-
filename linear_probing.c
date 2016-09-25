#include<stdio.h>
#include<limits.h>
#define HASH(data,n,i) ((data % n) + i) % n

void insert(int a[], int data, int n){
	int i = 0;
	int pos = HASH(data,n,i);
	while (i != n){
		if(a[pos] == 0){
			a[pos] = data;
			break;
		}
		i++;
		pos = HASH(data,n,i);
	}
	if(i == n)
		printf("HASH TABEL OVERFLOW\n");

}

void show(int a[], int n){
	int i = 0;
	while (i < n){
		printf("| %d |\n",a[i]);
		i++;
	}
}
	
void search(int a[], int data, int n){
	int i = 0;
	int pos = HASH(data,n,i);
	while ( i != n || a[pos] != 0){
		if( a[pos] == data){
			printf("%d IS FOUND\n",data);
			break;
		}
		i++;
		pos = HASH(data,n,i);
	}
	if( i == n || a[pos] == 0)
		printf("%d DATA IS NOT FOUND\n",data);
}
		
void delete(int a[], int data, int n){
	int i = 0;
	int pos = HASH(data,n,i);
	while(i != n || a[pos] != 0){
		if(a[pos] == data){
			a[pos] = INT_MIN;
			printf("ITEM DELETED\n");
			break;
		}
		i++;
		pos = HASH(data,n,i);
	}
	
	if(i == n || a[pos] == 0)
		printf("%d IS NOT IN HASH TABEL\n",data);
}
	



int main(){
	
	int a[100] = {0},n,data;
	scanf("%d",&n);
	while( 1 ){
		scanf("%6d",&data);
		if(data == -1)
			break;
		insert(a,data,n);
	}
	show(a,n);
	scanf("%d",&data);
	search(a,data,n);
	scanf("%d",&data);
	delete(a,data,n);
	show(a,n);
	return 0;
}	
