#include<stdio.h>//从终端输入一个字符，如果是十六进制数字，输出对应的整数，否则输出对应的字符码； 
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
