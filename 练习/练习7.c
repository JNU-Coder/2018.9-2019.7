#include<stdio.h>
#define in 1
#define out 0//�������һ���ַ����Ƶ��������ɾ��ǰ���ո� 
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
