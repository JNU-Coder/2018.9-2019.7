#include<stdio.h>
#define size 3
int main(void)
{
	int x[size]={1,3,5},k;
	printf("the value of x is 0x%x\n",x);
	for(k=0;k<size;k++)
	    printf("k=%d\tx[%d]=%d\taddr=0x%x\n",k,k,x[k],&x[k]);
	return 0;
 } 
