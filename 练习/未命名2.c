#include<stdio.h>
int main(void)
{
	int s[2][3],i,j,sum=0;
	for(i=0;i<2;i++)
	for(j=0;j<3;j++)
	{
		scanf("%d",&s[i][j]);
	}
	for(i=0;i<2;i++)
	for(j=0;j<3;j++)
	sum=sum+s[i][j];
	printf("%d",sum);
 } 
