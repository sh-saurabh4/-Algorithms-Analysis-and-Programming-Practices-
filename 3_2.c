#include<stdio.h>
#include<malloc.h>

int main()
{
	int n,i,j,data,sum = 0,temp,index,**a;
	//int a[100][100];	
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		a = (int **)malloc(n *sizeof(int *));
	for(i = 0; i < n; i++)
		a[i] = (int *)malloc(n * sizeof(int));
	//printf("size=%lu",(n*n)*sizeof(int));
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d",&(a[i][j]));
		}
	}
/*	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ",a[i][j]);
		}printf("\n");
	}	
*/	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == j){
				sum = 0;
				if(i - 1 >= 0 )
					sum += a[i - 1][j];
				if(i + 1 < n)
					sum += a[i+1][j];
				if(j - 1 >= 0 )
					sum += a[i][j - 1];
				if(j + 1 < n)
					sum += a[i][j + 1];
				if((i - 1 >= 0) && (j - 1 >= 0))
					sum += a[i - 1][j - 1];
				if((i + 1 < n) && (j + 1 < n))
					sum += a[i + 1][j + 1];
				if((i - 1 >= 0) && (j + 1 < n))
					sum += a[i -1][j + 1];
				if((i + 1 < n) && (j - 1 >= 0))
					sum += a[i + 1][j - 1];
				printf("%d: %d\n",a[i][j],sum);	
			
				if(i == 0)
					temp == sum;
				else{
					if( temp < sum ){
						temp = sum;
						index = i;
					}
				}
			}
				
		}
	}
	printf("index: %d\n",index+1);
	return 0;
}
