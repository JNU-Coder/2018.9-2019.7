#include<stdio.h>//从一个字符串中除去多余的空格 
int main(void) 
{
	char s[100]={0},a[100]={0};
	int i,j,k,t;
	printf("please input the string :\n");
	gets(s);
	/*不以空格结束，以回车结束，则使用gets() ;以回车或空格结束，
	则用scanf（"%s",s);以数组长度结束，则使用scanf("%c",&s[i]); */
	for(i=0,j=0,k=0;i<100;i++)
	{
		k=0;
		if(s[i]==' ')
		for(t=i;s[t]==' ';t++)
		{
			k++;
		}
		if(k>1)
		{
			i=t-1;
			a[j]=' ';
			j++;
		}
		else
		{
			a[j]=s[i];
			j++;
		}
	} 
	for(i=0;i<100;i++) printf("%c",a[i]);
	printf("\n");
	return 0;
}
