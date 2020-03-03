#include<stdio.h>
int main(void)
{
	float s[3][4];
	float (*p)[4];
	float sum=0;
	p=s;
	int i,j;
	for(i=0;i<3;i++)
	for(j=0;j<4;j++){
		scanf("%f",s[i]+j);//*(p+i)+j等价于&s[i][j]或s[i]+j;
		sum+=*(*(p+i)+j);
	}
	printf("%f",sum/12);
	return 0;
 } 
