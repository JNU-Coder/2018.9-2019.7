#include<stdio.h>
int main(void)
{
	float a,b,c;
	scanf("%f,%f,%f",&a,&b,&c);
	float i,j;
	if((a<=b&&a>=c)||(a<=c&&a>=b))printf("A:%f",a);
	if((b<=c&&b>=a)||(b<=a&&b>=c))printf("B:%f",b);
	if((c<=a&&c>=b)||(c<=b&&c>=a))printf("C:%f",c);
	return 0;
}
