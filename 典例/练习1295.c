#include<stdio.h>
int main(void)
{
	int s[2][2],i,j,*p;
	p=s;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			scanf("%d",&s[i][j]);	
		}	
		printf("%d\n%d\n",s[1][1],*(p+1)[1]);
} 
