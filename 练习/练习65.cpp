#include<stdio.h>
#include<string.h>
char* reverse_string(char *string)
{
	char *s1;
	char temp;
	s1=string+strlen(string)-1;
	while(string<s1)
	{
		temp=*string;
		*string++=*s1;
		*s1--=temp;
	}
	return string;
}
int main(void)
{
	char* reverse_string(char *string);
	char string[10];
	printf("please input string:\n");
	gets(string);
	printf("%s\n",reverse_string(string));
	return 0;
}
