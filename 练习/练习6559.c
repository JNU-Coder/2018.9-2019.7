#include<stdio.h>
int main(void)
{
	int i,j,n,k;
	printf("please input the n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(k=0;k<i;k++){
			printf(" ");
		}
		for(j=i;j<n;j++){
			printf(" *");
		}
		printf("\n");
	}
	return 0;
}
