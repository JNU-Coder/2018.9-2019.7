#include<stdio.h>
int main(void)
{
	int a[10],*p1,*p2;
	p1=&a[0];
	p2=&a[9];
	printf("%d\n",p2-p1);
	return 0;//Ö¸ÕëµÄÔËËã 
}
