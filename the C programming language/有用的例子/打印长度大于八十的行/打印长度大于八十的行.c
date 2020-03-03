#include<stdio.h>
#define MAXLINE 1000
int getline(char s[],int lim);
void copy(char to[],char from []);
int main(viod) 
{
	int len;
	int min;
	char line[MAXLINE];
	char longest[MAXLINE];
	min=80;
	while((len=getline(line,MAXLINE))>0)
	   if(len>min){
	   	min=len;
	   	copy(longest,line);
	   }
	if(min>80)
	    printf("%s",longest);
	return 0;
}
int getline(char s[],int lim)
{
	int c,i;
	for (i=0;i<lim-1&&(c=getchar())!=EOF && c!='\n';++i)
	    s[i]=c;
	if (c=='\n'){
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}
void copy(char to[],char from[])
{
	int i;
	i=0;
	while ((to[i]=from[i])!='\0')
	    ++i;
}
 
