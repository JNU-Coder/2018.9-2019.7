#include<stdio.h>
int main(void)
{
	char s[20],a[20],k;
	int i,j;
	printf("please input k:\n");
	scanf("%c",&k);
	printf("please input s:\n");
	for(i=0;i<20;i++) scanf("%c",&s[i]);
	for(i=0,j=0;i<20;i++)
	{
		if(s[i]!=k){
			a[j]=s[i];
			j++;
		}
	}
	printf("%s",a);
	return 0;/2
 } 
