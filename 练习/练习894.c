#include<stdio.h>
int main(void)
{
	const n=10ul;//只能添加long或者unsignedlong类型 即u||l||ul 
	int i,s[n];
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for(i=0;i<n;i++)
	printf("%d\n",s[i]);
	return 0;
	
}
