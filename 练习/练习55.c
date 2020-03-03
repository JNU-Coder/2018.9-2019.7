#include<stdio.h>//验证哥德巴赫猜想 
int prime(int n)
{
	int i=1,j=0;
	for(;i<=n;i++)
	{
		if((n%i)==0)
		j++;
	}
	if(j==2)
	return n;
	else 
	return 0;
}
int h(int b,int e)
{
 	int n;
 	printf("please input n:\n");
 	scanf("%d",&n);
 	if(n<10||n>20||(n%2)!=0)
 	{
 		printf("input error!\n");
	}
	else
	{
		int i,j;
		b=0,e=0;
		for(j=1;j<=n;j++)
		{
			i=n-j;
			b=prime(i);
			e=prime(j);
			if((b+e)==n)
			{
				printf("%d=%d+%d\n",n,b,e);	
			}
		}	
	}
	printf("\n");
}
int main(void)
{
	int b=0,e=0;
	h(b,e);
	return 0;
}
 
 
 
 
 
 
 
 
