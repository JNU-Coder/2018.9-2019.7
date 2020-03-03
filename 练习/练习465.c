#include<stdio.h>//从一个字符串中提取一个子字符串，并返回其长度 
#define MAX 40
int main()
{
	char s[MAX],c[MAX];
	int n,len=0;
	printf("please input s:\n");
	scanf("%s",s);
	printf("please input n:\n");
	scanf("%d",&n);
	int i,j;
	for(j=0,i=(n-1);i<(n+len);i++)
	{
		if(s[i]!='\0'){
			c[j]=s[i];
			j++;
			len++;
		}
	}
	printf("%s\n",c);
	printf("%d",len);
	return 0;
} 
