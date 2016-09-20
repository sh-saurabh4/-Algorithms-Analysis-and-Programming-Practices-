#include<stdio.h>
int sort(int t[], int n){
	int i,j,temp;
	for (i = 0; i < n; i++){
		for (j = i; j < n; j++){
			if(t[i] > t[j] ){
				temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
	return 0;
}
void show(int t[], int n){
	int i,temp;
	for(i = 0; i < n; i++){
		if(i == 0){
			temp = t[i];
			printf("%d ",t[i]);
		}
		else if(t[i] != temp){
			temp = t[i];
			printf("%d ",t[i]);
		}
	}printf("\n");
	return ;
}


int main()
{
	int i,j,n;
	scanf("%d",&n);
	int a[n][n],t[n*n];
	for( i = 0; i < n; i++){
		for( j = 0; j < n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Along rows:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			t[j] = a[i][j];
			
		}
		sort(t,n);
		show(t,n);
	}
	
	printf("Along columns:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			t[j] = a[j][i];
		}
		sort(t,n);
		show(t,n);
	}
	
	int k = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			t[k] = a[i][j];
			k++;
		}
	}
	sort(t,k);
	printf("Matrix:\n");
	show(t,k);

	return 0;
}
