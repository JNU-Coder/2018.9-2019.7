#include<stdio.h>
int main(void)
{
	char *p,s[10];//20���ֽڣ�������20���ַ� 
	int num;
	gets(s);//������������������20������������ȷ����� 
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
