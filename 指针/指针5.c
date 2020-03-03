#include<stdio.h>
int main(void)
{
	int a[10],*p,*pmax;
	printf("input:\n");
	for(p=a;p<a+10;p++)
		scanf("%d",p);
	pmax=a;
	p=a+1;
	for(;p<a+10;p++){
		if(*p>*pmax)
			pmax=p;
	}
	printf("the max is %d\n",*pmax);//输出指针所指向的对象 
	printf("the position of it is %d\n",pmax-a);//即输出两指针相差的储存单位个数 
	return 0;
 } 
