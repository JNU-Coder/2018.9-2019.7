#include<stdio.h>
int main(void)
{
	int i[2];
	int *p;
	p=&i[0];
	scanf("%d,%d",p,(p+1));
	if(i[0]>i[1])
	printf("%d\n",*p);
	else
	printf("%d\n",*(p+1));
	return 0;
 } 
