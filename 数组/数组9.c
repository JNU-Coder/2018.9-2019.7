#include<stdio.h>
int main(void)
{
	int s[10],i,max,min;
	for(i=0;i<10;i++)
	scanf("%d",&s[i]);
	max=min=s[0];
	for(i=1;i<10;i++)
	{
		if(max<=s[i])
		max=s[i];
		else if(min>=s[i])
		min=s[i];
	}
	printf("%d\n%d",max,min);
	return 0;
 } 
