#include<stdio.h>
#define in 1
#define out 0
int main(void)
{
	int state=out;
	char c;
	printf("please:\n");
	while((c=getchar())!=EOF){//输入字符 
		if(state==out){//输出字符，并且判断是否为space 
			putchar(c);
			if(c==' ')state=in;
		}
		if(state==in&&c!=' '){
			state=out;//若为space，则不输出，若为其他字符，则输出 
			putchar(c);
		} 
	}
	return 0;
}
