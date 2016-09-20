#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(char *a, char *b);
void sort(char **a, int n){
	int i,j,t;
	char *temp;
	
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			t = comp(a[i],a[j]);
			if(t == 2){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
		
}				



int comp(char *a, char *b){
	int i,l,l1,l2,t1,t2;
	l1 = strlen(a);
	l2 = strlen(b);
	if(l1 <= l2)
		l = l1;
	else
		l = l2;

	for(i = 0; i < l; i++){
		if (a[i] >= 97)
			t1 = a[i] - 'a';
		else
			t1 = a[i] - 'A';
		if (b[i] >= 97)
			t2 = b[i] - 'a';
		else
			t2 = b[i] - 'A';
		if( t1 < t2)
			return 1;
		else if ( t2 < t1 )
			return 2;
		else
			continue;
	}
	return 1;
}	

void show(char **a, int n){
	int i;
	for( i = 0; i < n; i++){
		printf("%s ",a[i]);
	}
	printf("\n");
}
void unishow(char **a, int n){
	int i;
	int temp = 0,c;
        for( i = 0; i < n; i++){
                if(i != 0)
			c = strcmp(a[i],a[temp]);
		if(c != 0){
			printf("%s ",a[i]);
			temp = i;
		}
	}
	printf("\n");
}
	
int main()
{
	int n,i,j;
	char **a;
	scanf("%d",&n);
	
	a = (char **)malloc(n*sizeof(char *));
	for(i = 0; i < n; i++){
		a[i] = (char *)malloc(50 * sizeof(char));
	}
	
	for(i = 0; i < n; i++){
		scanf("%s",a[i]);
	}
	sort(a,n);		
	printf("Sorted:\n");
	show(a,n);
	printf("Unique:\n");
	unishow(a,n);
	return 0;
}
