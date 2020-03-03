#include<stdio.h>
int main(void)
{
	int s[10],i,n;
	printf("please input numbers:\n");
	for(i=0;i<10;i++)
	scanf("%d",&s[i]);
	printf("please input the n one you want to delete:\n"); 
	scanf("%d",&n);
	for(i=n-1;i<9;i++)
	{
		s[i]=s[i+1];
	}
	for(i=0;i<9;i++)
	printf("%d\t",s[i]);
	return 0;
 } 
