#include<stdio.h>//求质数之Eratosthenes筛选法
#include<math.h>
#define TRUE 1
#define FLASE 0
int main(void)
{
	char s[1000000]={0};
	int n,m,i,j;
	char *k;
	k=s;
	printf("请输入上限n(n<=1000000):\n");
	scanf("%d",&n);
	for(j=3;j<=n;j+=2)
	{
		for(i=3;i<=n;i++)
		{	
			if(j==i)
			{
				m=(j-1)/2;
				*(k+m)='1';
			}
			if(j%i==0)
			break;
		}
	}
	for(i=0;i<1000000;i++)
	{
		if(*(k+i)=='1') printf("%d\t",(2*(i+1)-1));
	}
	printf("\n");
	return 0;
}
