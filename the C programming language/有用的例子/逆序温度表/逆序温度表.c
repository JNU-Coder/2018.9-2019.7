#include<stdio.h>
int main(void)
{
	float F,C;
	int lower,upper,step;
	lower=0;
	upper=300;
	step=20;
	F=upper;
	while (F>=lower)
	{
		C=(5.0/9.0)*(F-32.0);
	printf("%3.0f %6.1f\n",F,C);
	F=F-step;
	}
 } 
