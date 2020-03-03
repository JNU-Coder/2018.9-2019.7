#include<stdio.h>
int main(void)
{
	int i,j;
	char d[3][3]={{'*','*','*'},{'*','*','*'},{'*','*','*'}};
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		printf("%c",d[i][j]);
		printf("\n");
	}
	return 0;
 }
