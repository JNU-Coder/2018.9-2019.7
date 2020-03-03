#include<stdio.h>//将字符数字转换为整型数字 
#include<string.h>
int a(char *string)
{
	int i=0,j=0,r=0;
	while(i<(strlen(string)))
	{
		if((*(string+i)>='0')&&(*(string+i)<='9'))
		{
			j=*(string+i)-'0';
			r=r*10+j;
			i++;
		}
		else 
		{
			r=0;
			break;
		}
	}
	if(r==0) printf("error!\n");
	else return r;	
} 
int main(void)
{
	char string[1000];
	printf("please input string:\n");
	gets(string);
	printf("%d\n",a(string));
	return 0;
}
