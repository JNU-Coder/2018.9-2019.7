#include<stdio.h>
long long fac(int n){
	long long m=1;
	if(n==0||n==1){
		m=1;
	}
	else
	{
		m=n*fac(n-1); //函数的递归调用！！!!!!！！！！ 
	}
	return m;
} 
int main(void)
{
	int n;
	printf("please input n:\n");
	scanf("%d",&n);
	printf("%lld",fac(n));
	return 0;
}
