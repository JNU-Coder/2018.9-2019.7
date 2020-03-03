#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define MAXSIZE 50
 
int mystrlen(const char *strDest)
{
	assert(NULL != strDest);		//assert����ڼ��
	if('\0' == *strDest)			//�ַ�������
		return 0;
	else
		return (1 + mystrlen(++strDest));		//�ݹ�����ַ�������
}
 
int main(void)
{
	char *ch;
	int len;
	
	ch = (char*)malloc(sizeof(char)*MAXSIZE);
 
	printf("Input a string:");
	scanf("%s", ch);
	len = mystrlen(ch);
	printf("%d", len);
	printf("\n");
	return 0;
}

