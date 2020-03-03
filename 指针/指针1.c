#include<stdio.h>
int main(void)
{
	int x;
	printf("please input x:\n");
	scanf("%d",&x);
	int *p=&x;
	printf("%d",p);
	return 0;
 } //取地址符与间接寻地址符的使用 
