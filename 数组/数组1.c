#include<stdio.h>
#include<string.h>
int main(void)
{
	int s[10],i,L,H,sum=0;
	float A;
	printf("please input scaores:\n");
	for(i=0;i<10;i++)
	scanf("%d",&s[i]);
	L=H=s[0];
	for(i=0;i<10;i++)
	{
		sum+=s[i];
	if(s[i]<L)
		L=s[i];
	if(s[i]>H)
		H=s[i];
	}
	A=sum/10.0;
	printf("%d,%d,%f",L,H,A);
	return 0;
 } 
