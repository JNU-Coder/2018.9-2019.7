#include<stdio.h>
void swap(int a,int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
	printf("%d,%d\n",a,b);
}
int main(void)
{
	int a,b;
	printf("please input a&b:\n");
	scanf("%d,%d",&a,&b);
	swap(a,b);
	printf("%d,%d",a,b);
	return 0;
}//假交换，实际参数的真值未改变！！！！！ 
