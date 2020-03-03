#include<stdio.h>
#define size 30
int main(void)
{
	int s[size];
	int k,i,t,n;
	scanf("%d",&n);
	for(i=0;i<=k;i++)
		scanf("%d",&s[i]);
	k=n/2;
	for(i=0;i<=k;i++)
		{
			t=s[i];
			s[i]=s[n-i-1];
			s[n-i-1]=t;
		}
		for(i=0;i<n;i++)
			printf("%4d",s[i]);
		return 0;
}
