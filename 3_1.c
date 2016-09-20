#include<stdio.h>
#include<malloc.h>
int main()
{
	int n,i,sum = 0,data,nde,result;
	scanf("%d",&n);
	//arr = (int **)malloc(n * sizeof(int));
	for ( i = 0; i < n ; i++){
			scanf("%d",&data);
			sum += data;
	}
	nde = (n * n) - n;
	if (sum % nde == 0)
		result = (sum / nde) + 1 ;
	else
		result = (sum / nde) + 1;
	printf("%d\n",result);
	return 0;
}

