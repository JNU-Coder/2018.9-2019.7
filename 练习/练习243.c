#include<stdio.h>
int main(void)
{
	int del(char *str,char const substr);
	char str[100]={'\0'},substr[100]={'\0'};
	printf("please input str:\n");
	gets(str);
	printf("please inpu substr:\n");
	gets(substr);
	int i,j,k,t,n,m;
	for(i=0;i<100;i++)
	{
		m=i;
		for(j=0,k=0,n=0,t=0;j<100;j++)
		{
			t=i;
			if(*(substr+j)='\0') break;
			if(*(str+t)!=*(substr+j)) break;
			else
			{
				t++;
				k++;
				n=i;
			}''
		}
		if(k!=j) break;
	}
	for(i=0;i<(100-n-1);i++)
	{
		if(k==j)
		{
			*(str+m)=*(substr+i+n);
		}
	}
	printf("%s",str);
	return 0;
}
