#include<stdio.h>//计算厄米多项式 
int hermite(int n,int x)
{
	if(n<=0) return 1;
	if(n=1) return 2*x;
	if(n>=2) return (2*x*(her0mite(n-1,x))-2*(n-1)*(hermite(n-2,x)));
};
int main(void)
{
	printf("please input n&x:\n");
	int n,x;
	scanf("%d,%d",&n,&x);
	printf("%d\n",hermite(n,x));
	return 0;
}
