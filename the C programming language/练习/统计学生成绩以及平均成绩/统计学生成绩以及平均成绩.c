#include<stdio.h>
#define N 37
int main(void)
{
	int score[N],i,sum;
	sum=0;
	double x;
	for(i=0;i<N;i++)
	    scanf("%d",&score[i]);
	for(i=0;i<N;i++)
	    sum+=score[i];
	x=sum*1.0/N;//·ÀÖ¹½Ø¶ÏÎó²î 
	printf("x=%f",x);
	return 0;
}
