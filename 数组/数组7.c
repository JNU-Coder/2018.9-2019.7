#include<stdio.h>
#define n 10
#define wideword 6 
int main(void)
{
	int a[11],b[11],i,j;
	for(i=0;i<n;i++){
		for(j=1;j<i;j++)
		a[j]=b[j-1]+b[j];
		a[i]=1;
		for(j=0;j<=40-i*(wideword/2);j++)
		printf("%c",' ');
		for(j=0;j<=i;j++)
		printf("%6d",a[j]);
		printf("\n");
	}
	return 0;
 } 
