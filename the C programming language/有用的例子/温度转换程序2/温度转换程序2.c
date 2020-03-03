#include<stdio.h>
float c(float f);
int main(void)
{
	float f;
	int lower ,upper,step;
	
	
	lower=0;
	upper=300;
	step=20;
	
	
	f=lower;
	while (f<=upper){
		printf("%3.0f%6.1f\n",f,c(f));
		f=f+step;
	}
}
float c(float f)
{
	return (5.0/9.0)*(f-32.0);
}
