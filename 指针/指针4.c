#include<stdio.h>
int main(void)
{
	int a[10],i;
	float sum=0;
	printf("enter 10 integers:\n");
	for(i=0;i<10;i++)//*���Ѱ��ַ�����ڷ���ָ����ָ�Ķ��� 
	{
		scanf("%d",a+i);//a+i��&a[i]�ǵ�Ч�� 
		sum+=*(a+i);//*��a+i)��a[i[�ǵ�Ч�� 
	}
	printf("the average of 10 integers is %f\n",sum/10);
	return 0;
 } 
