#include<stdio.h>
#define in 1
#define out 0
int main(void)
{
	int state=out;
	char c;
	printf("please:\n");
	while((c=getchar())!=EOF){//�����ַ� 
		if(state==out){//����ַ��������ж��Ƿ�Ϊspace 
			putchar(c);
			if(c==' ')state=in;
		}
		if(state==in&&c!=' '){
			state=out;//��Ϊspace�����������Ϊ�����ַ�������� 
			putchar(c);
		} 
	}
	return 0;
}
