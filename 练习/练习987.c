#include<stdio.h>
int main(void)
{
	char s[50000];
	int i,j,k,z;
	for(i=0;s[i-1]!=EOF;i++)//scanf函数无法输入EOF，会被忽略！ 
	{
		s[i]=getchar();
		z=i;
	}
	for(i=0,j=0,k=0;i<z;i++)
	{
		if(s[i]=='{') j++;
		if(s[i]=='}') k++;
	}
	if(j!=k) printf("error!\n");
	else printf("correct!\n");
	return 0;
}
