#include<stdio.h>
int main(void)
{
	int a[2][4],*p;
	int i,j,sum=0;
	p=&a[0][0];//≥ı ºªØ 
	printf("enter the array:\n");
	for(i=0;i<2;i++)
	for(j=0;j<4;j++)
	{
		scanf("%d",p);
		sum+=*p;
		p++;
	}
	printf("the sum of the array is %d \n",sum);
	return 0;
}
