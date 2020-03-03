#include<stdio.h>
int main(void)
{
	char *p,s[10];//20个字节，能容纳20个字符 
	int num;
	gets(s);//所以这里最多可以输入20个，而产生正确结果； 
	p=s;
	while(*p!='\0')
	{
		if(*p=='i')
		num++;
		p++;
	}
	printf("num is %d\n",num);
	return 0;
}
