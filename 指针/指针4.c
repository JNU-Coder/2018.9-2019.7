#include<stdio.h>
int main(void)
{
	int a[10],i;
	float sum=0;
	printf("enter 10 integers:\n");
	for(i=0;i<10;i++)//*间接寻地址符用于访问指针所指的对象 
	{
		scanf("%d",a+i);//a+i和&a[i]是等效的 
		sum+=*(a+i);//*（a+i)和a[i[是等效的 
	}
	printf("the average of 10 integers is %f\n",sum/10);
	return 0;
 } 
