#include<stdio.h>//���ն�����һ���ַ��������ʮ���������֣������Ӧ�����������������Ӧ���ַ��룻 
int main(void)
{
	char c;
	c=getchar();
	if((c>='0'&&c<='9')||(c>='A'&&c<='F')){
		if(c>='0'&&c<='9')
		printf("%c",c);
		if(c=='A')printf("10");
		if(c=='B')printf("11");
		if(c=='C')printf("12");
		if(c=='D')printf("13");
		if(c=='E')printf("14");
		if(c=='F')printf("15");
	}
	else printf("%d",c);
	return 0;
}
