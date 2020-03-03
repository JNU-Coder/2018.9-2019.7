#include<stdio.h>//将整型数字转换为字符型数字 
void b(unsigned int value)
{
	unsigned int quotient;
	quotient=value/10;
	if(quotient!=0)
	b(quotient);
	putchar(value%10+'0');
 } 
 int main()
 {
 	unsigned int m;
 	printf("please input m:\n");
 	scanf("%u",&m);
 	b(m);
 	return 0;
 }
