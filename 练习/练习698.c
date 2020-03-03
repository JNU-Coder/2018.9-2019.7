#include<stdio.h>//¼ÓÃÜ×ÖÄ¸ 
int main(void)
{
	char ch,s[100]={'\0'};
	int i;
	printf("please input s[]:\n");
	for(i=0;i<100;i++)
	{
		if((ch=getchar())==EOF) break;
		if((ch>='A')&&(ch<='M'))  s[i]=ch+13;
		else if((ch>='N')&&(ch<='Z')) s[i]=ch-13;
		else s[i]=ch;
	} 
	for(i=0;i<100;i++)printf("%c",s[i]);
	return 0;
}


