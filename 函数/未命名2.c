#include<stdio.h>
#include"getline����.h"
#include"copy����.h"
#define MAXLINE 1000
int main(void) 
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

