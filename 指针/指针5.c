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
	printf("the max is %d\n",*pmax);//���ָ����ָ��Ķ��� 
	printf("the position of it is %d\n",pmax-a);//�������ָ�����Ĵ��浥λ���� 
	return 0;
 } 
