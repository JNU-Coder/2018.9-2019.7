#include<stdio.h>//输入数，求其第K位的数字 
#include<math.h>
int h(int n,int k)
{
	int i=0,s=0;
	printf("please input n:\n");
	scanf("%d",&n);
	printf("please input k:\n");
	scanf("%d",&k);
	if(n/(pow(10,k))<1)
	{
		return -1;
	}
	else 
	{
		i=(n/(pow(10,k-1)));
		s=(i%10);
		return s;
	}
}
int main(void)
{
	int l,n,k;
	l=h(n,k);
	printf("%d",l);
	return 0;
}
