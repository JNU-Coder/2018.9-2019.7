#include<stdio.h>
#define in 1
#define out 0//将输入的一行字符复制到输出，并删除前导空格 
int main(void)
{
	int state=out;
	char c;
	printf("please input :\n");
	while((c=getchar())!=EOF)
	{
		if(state==out)
		{
			if(c!=' ')
			{
				putchar(c);
				state=in;
			}
		}
		if(state==in){
			putchar(c);
			if(c=='\n'){
				state=out;
			}
		}
	}
	return 0;
}
