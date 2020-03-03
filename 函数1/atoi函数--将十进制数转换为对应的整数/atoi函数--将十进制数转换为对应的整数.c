#include<stdio.h>
int atoi(char s[]);
int main(void)
{
	int i;
	char s[100];
	printf("please input the s[]:\n");
	scanf("%d",&s[100]);
    int sb=atoi(char s[100]);
	printf("%d",sb);
}
#define base 10
int atoi(char s[])
{
	int j=0,num=0;
	for(;s[j]!='\0';j++)
	    num=num*base+s[j]-'0';
    return num;
 } 
