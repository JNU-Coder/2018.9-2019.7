#include<stdio.h>
int main(void)
{
	int s[10],i,j,k,r;
	printf("please input numbers:\n");
	for(i=0;i<10;i++)
		scanf("%d",&s[i]);
	printf("\n");
	for(i=0;i<9;i++)
		{
			j=i;
			for(k=i+1;k<10;k++)
				if(s[k]<s[j])
				j=k;
			r=s[i];
			s[i]=s[j];
			s[j]=r;
		}
	for(i=0;i<10;i++)
		{
			printf("%d\n",s[i]);
		}
	return 0;
}
