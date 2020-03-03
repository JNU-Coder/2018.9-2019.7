#include<stdio.h>
int main(void)
{
	int i=2;
	printf("%d%d%d",i*=2,++i,i++);
	printf("\n%d\n",i);
	return 0;
 } 
