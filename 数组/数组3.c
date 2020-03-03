#include<stdio.h>
int main(void)
{
	int s[20],i,sum=0;
	printf("please input s[0],s[1]:\n");
	scanf("%d,%d",&s[0],&s[1]);
	for(i=1;i<19;i++)
		s[i+1]=s[i]+s[i-1];
	for(i=0;i<20;i++)
		sum=sum+s[i];
	printf("%d",sum);
	return 0;
}

