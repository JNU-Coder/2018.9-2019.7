#include<stdio.h>
int main(void)
{
	const n=10ul;//ֻ�����long����unsignedlong���� ��u||l||ul 
	int i,s[n];
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for(i=0;i<n;i++)
	printf("%d\n",s[i]);
	return 0;
	
}
