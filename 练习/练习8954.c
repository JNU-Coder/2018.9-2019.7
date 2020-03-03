#include<stdio.h>
char *find_char(char const *source,char const *chars)
{
	int i,j,k;
	char *ch;
	for(i=0;;i++)
	{
		ch=(source+i);
		for(j=0;;j++)
		{
			if(*(source+i)==*(chars+j))	return (ch);
			else {ch=NULL;return ch;
			}
		}	
	}	
};
int main(void)
{
	char *find_char(char const *source,char const *chars);
	char source[100],chars[100];
	char *pr;
	printf("please input source[]:\n");
	scanf("%s",source);
	printf("please input chars[]:\n");
	scanf("%s",chars);
	pr=*find_char(source,chars);
	printf("%d",*pr);
	return 0;
} 
