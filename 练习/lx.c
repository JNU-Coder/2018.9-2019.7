#include<stdio.h>//ËãÊı¼¶Êı 
int h(int a,int d,int k)
{
	int i,j;
	printf("please input a&d:\n");
	scanf("%d,%d",&a,&d);
	printf("please input j:\n");
	scanf("%d",&j);
	for(k=1,i=0;k<=j;k++)
	{
		i=a+(k-1)*d;
		printf("%d",i);
		putchar('\t');
	}
}
int main(void)
{
	int a,d,k,j,z;
	z=h(a,d,k);
	return 0;
}
