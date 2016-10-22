#include<stdio.h>
int main()
{
	int n,sum,i,j;
	scanf("%d",&n);
	int a[n][n],row[n],col[n];
	for (i = 0; i < n; i++){
		sum = 0;
		for (j = 0; j < n; j++){
			
			scanf("%d",&a[i][j]);
			sum += a[i][j];
		}
	row[i] = sum; 
	}
	
	for (j = 0; j < n; j++){
		sum = 0;
		for (i = 0; i < n; i++){
			
			sum += a[i][j];
		}
	col[j] = sum;
	}

	for ( i = 0; i < n; i++){
		for(j = 0; j < n; j++){//printf("%d-%d ",row[i],col[j]);
			if(row[i] == col[j]){
				printf("row: %d\n",i+1);
				printf("col: %d\n",j+1);
			}
		}//printf("\n");
	}
	return 0;
}
