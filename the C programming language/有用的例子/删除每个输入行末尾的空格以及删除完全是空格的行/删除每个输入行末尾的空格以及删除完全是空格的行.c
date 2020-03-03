#include<stdio.h>
#define MAXLINE 1000
int getline(char line[],int maxline);
int reverse(char s[]);
int main(void)
{
	char line[MAXLINE];
	while(getline(line,MAXLINE)>0)
		if (remove(line)>0);
		    printf("%s",line);
	return 0;
}
int reverse(char s[])
{
	int i;
	i=0;
	while(s[i]!='\n')
		++i;
	--i;
	while (i>=0&&(s[i]==' '||s[i]=='\t'))
		--i;
	if (i>=0){
		++i;
		s[i]='\n';
		++i;
		s[i]='\0';
	}
	return i;
}
int getline(char s[],int lim)
{
	int c,i;
	for (i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
	    s[i]=c;
	if (c=='\n'){
		s[i]=c;
		++i;
	}
		s[i]='\0';
		return i;
}
