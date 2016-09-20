#include<stdio.h>
void trans(int a[][100], int *m, int *n ){
	int i,j,b[100][100];
	for(i = 0; i < *m; i++){
		for(j = 0; j < *n; j++){
			b[j][i] = a[i][j];
		}
	}
	for(i = 0; i < *n; i++){
		for(j = 0; j < *m; j++){
			a[i][j] = b[i][j];
		}
	}
}


int main()
{
	int m,n,j,i;
	scanf("%d%d",&m,&n);
	int a[100][100];
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	trans(a,&m,&n);
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ",a[i][j]);
		}printf("\n");
	}
	return 0;
}
