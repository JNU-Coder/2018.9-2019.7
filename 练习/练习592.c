/**************************************** 
*  File Name  : max_list.c 
*  Creat Data : 2015.1.21
*  Author     : ZY 
*****************************************/ 
 
/*编写一个名叫max_list的函数，它用于检查任意数目的整
型参数并返回他们中的最大值。参数列表必须以一个负值结
尾，提示列表结束。*/
 
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

 
