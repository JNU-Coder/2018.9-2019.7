#include<stdio.h>//输入一个英文字母，输出相应的二维字符图形 
int main(void)
{
	char ch;
	int i,j,k;
	printf("please input a charact:\n");
	scanf("%c",&ch);
	if(ch>='a'&&ch<='z')
	{
		for(i=96;i<ch;i++)
		{
			for(j=i+1;j<=ch;j++)
			{
				printf("%c",j);
			}
			for(k=96;k<=i;k++)
			{
			 	if(k>96)
				{
					printf("%c",k);
				}
			}
			printf("\n");
		}
	}
	if(ch>='A'&&ch<='Z')
	{
		for(i=64;i<ch;i++)
		{
			for(j=i+1;j<=ch;j++)
			{
				printf("%c",j);	
			}
			for(k=64;k<=i;k++)
			{
				if(k>64)
				{
					printf("%c",k);
				}	
			}
			printf("\n");	
		}	
	}
	return 0;
}
