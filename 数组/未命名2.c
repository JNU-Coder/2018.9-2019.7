#include<stdio.h>
int main(void)
{
	int i,j,m,s[5],n[11];
	printf("please input 50integrt:\n");
	for(i=0;i<5;i++)
		scanf("%d",&s[i]);
	for(j=0;j<11;j++)
		n[j]=0;
	for(i=0 ;i<5;i++)
		{
			m=s[i]/10;//取整再作为标号数带入 
			n[m]++;
		}
	for(j=0;j<11;j++)
		printf("%3d--%3d:%6d\n",j*10,(j+1)*10-1,n[j]);
	return 0;
}
