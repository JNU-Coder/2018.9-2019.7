#include<stdio.h>
int main(void)
{
	int s[10],i,*p;
		printf("please input s[10]:\n");
	for(i=0;i<10;i++)
		scanf("%d",&s[i]);//��������ȡ��ַ�������� 
		printf("\n");
	p=&s[0];//��������ȡ��ַ������������ 
	p=p+2;
	printf("%d",*p);
	return 0;
}
