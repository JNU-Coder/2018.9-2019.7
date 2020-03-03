#include<stdio.h>
#define I 2
#define J 3
int mian(void)
{
	int u[I][J],(*p)[J]=u;
	int j;
	for(j=0;j<J;j++)
		scanf("%d",(u[0]+j));
	for(j=0;j<J;j++)
		scanf("%d",(*(u+1)+j));
	for(j=0;j<J;j++)
		printf("%6d",*(*(u+0)+j));
	printf("\n");
	for(j=0;j<J;j++)
		printf("%6d",*(u[1]+j));
	printf("\n");
	return 0;
 } 
