#include<stdio.h>//计算平方根 
int main(void)
{
	float a,n;
	printf("please input n:\n");
	scanf("%f",&n);
	int i=0;
	if(n<=0){
		printf("input error!\n");
		return 0;
	}
	else for(a=1;i<20;i++){
		a=(a+n/a)/2;
		printf("%f\n",a);
	}
	return 0;
} 
