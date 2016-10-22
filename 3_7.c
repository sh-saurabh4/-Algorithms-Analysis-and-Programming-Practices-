#include<stdio.h>
#include<string.h>
int palindrom(char *a,int len ){
	char *f,*l;
	int i;
	f = &a[0];
	l = &a[len-1];
	
	for(i = 0; i < len/2; i++){
		if(*f == *l){
			f++;
			l--;
		}
		else
			return 0;
	}
 	return 1;
	
}


int main()
{
	int n,i,j,len,t;
	scanf("%d",&n);
	char a[n][20];
	
	for (i = 0; i < n; i++){

		scanf("%s",a[i]);
		len = strlen(a[i]);
		t = palindrom(a[i],len);
		if(t == 1)
			printf("yes\n");
		else
			printf("no\n");
		
	}
	return 0;
}
