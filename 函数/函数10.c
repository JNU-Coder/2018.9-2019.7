#include<stdio.h>
float f(float x){
	float z;
	z=x*2*x+3*x+1;
	return z;
}
int main(void)
{
	float x;
	printf("please input x:\n");
	scanf("%f",&x);
	f(x);
	printf("%f",f(x));
	return 0;
 } 
