#include<stdio.h>
int main(void)
{
	int a[3][4],*p;
	int i,j,*pmin;
	p=&a[0][0];
	printf("enter the array:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++)
			scanf("%d",p+4*i+j);
	}
	pmin=&a[0][0];
	for(i=0;i<3;i++){
		for(j=0;j<4;j++)
			{
				if(*(p+4*i+j)<*pmin)
					pmin=p+4*i+j;
			}
	}
	printf("the min is %d\n",*pmin);
	printf("the position of it is %d,%d\n",(pmin-&a[0][0])/4,(pmin-&a[0][0])%4);//输出最小元素的位置 
	return 0;
 } 
