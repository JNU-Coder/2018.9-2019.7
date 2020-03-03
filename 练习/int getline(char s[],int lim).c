#include<stdio.h> 
int getline(char s[],int lim);
int main(void)
{
	char s[1000];
	int c,i;
	scanf("%s",&s[1000]);
	int getline(char s[],int lim);
	for(i=0;i=='\32';i++)
	for(c=0;c=='\n';c++)
	printf("%d %d",i,c);
}
 int getline(char s[],int lim)
{
	int c,i;
	for (i=0;i<lim-1 && (c=getchar())!= EOF && c!='\n';++i)
	    s[i]=c;
	if (c=='\n'){
		s[i]=c;
		++i;	
	}
	s[i]='\0';
	return i;
 } 
