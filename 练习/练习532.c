#include<stdio.h>
int main(void)
{
	char m,n;
	int i,j;
	float k;
	printf("input m,n:\n");
	scanf("%c%c",&m,&n);
	switch(m+1)
	{
		case '1':printf("*");break;
		default:printf("error!\n");
	}
	return 0;
 } 
