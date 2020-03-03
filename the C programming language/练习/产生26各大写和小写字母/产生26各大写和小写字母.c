#include<stdio.h>
int main(void)
{
	char cap[27],low[27];
	int i,delt='a'-'A';//'a'-'A'=0x20
	cap[0]='A';
	low[0]=cap[0]+delt;//'a'至low [0]
	for (i=1;i<26;i++){
		cap[i]=cap[i-1]+1;//'B''c'至cap[1]
		low[i]=low[i-1]+1;//'b'至low[1]
	}
	cap[26]='\0';//字符串终结符到CAP 
	low[26]=cap[26];//字符串终结符到LOW 
	printf("%s\n",cap);
	printf("%s\n",low);
	return 0;
 } 
