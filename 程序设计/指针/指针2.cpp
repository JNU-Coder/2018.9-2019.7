#include<stdio.h>
#define I 2
#define J 3
int mian(void)
{
	int u[I][J],(*p)[J]=u;
	int i;
	for(i=0;i<J;i++)
		scanf("%d",(u[0]+i));
	for(i=0;i<J;i++)
		scanf("%d",(*(u+1)+i));
	for(i=0;i<J;i++)
		printf("%6d",*(*(u+0)+i));
	putchar('\n');
	for(i=0;i<J;i++)
		printf("%6d",*(u[1]+i));
	putchar('\n');
	return 0;
 } 
