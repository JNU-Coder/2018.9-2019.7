/**************************************** 
*  File Name  : max_list.c 
*  Creat Data : 2015.1.21
*  Author     : ZY 
*****************************************/ 
 
/*��дһ������max_list�ĺ����������ڼ��������Ŀ����
�Ͳ��������������е����ֵ�������б������һ����ֵ��
β����ʾ�б������*/
 
#include <stdio.h>
#include <stdarg.h>
 
int max_list(int n_values,...)
{
    va_list var_arg;
	int max = 0;
	int tmp;
	va_start(var_arg,n_values);
	while((tmp = va_arg(var_arg,int )) >= 0)
	{
		max = (tmp  > max )?tmp:max;
	}
	va_end(var_arg);
	return max;
}
int main()
{
	printf("%d\n",max_list(10,23,34,45,67,98,-1));
	return 0;
} 

 
