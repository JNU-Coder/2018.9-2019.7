#include<stdio.h>
int main(void)
{
	int s[5][3],i,j,sum=0;
	float AC,AM,AE,AA;
	for(i=0;i<5;i++)
	for(j=0;j<3;j++)
	{
		scanf("%d",&s[i][j]);
	}
	for(j=0,i=0;i<5;i++)
	{
		sum=0;
		sum=s[i][0]+sum;
		AC=sum/5.0;
	}
	for(j=1,i=0;i<5;i++)
	{
		sum=0;
		sum=s[i][1]+sum;
		AM=sum/5.0;
	}
	for(j=2,i=0;i<5;i++)
	{
		sum=0;
		sum=s[i][2]+sum;
		AE=sum/5.0;
	}
	for(i=0;i<5;i++)
	for(j=0;j<3;j++)
	{
		sum=0;
		sum=s[i][j]+sum;
		AA=sum/5.0;
	}
	printf("%f,%f,%f,%f",AC,AM,AE,AA);
	return 0;
 } 
