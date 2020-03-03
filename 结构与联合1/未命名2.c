#include<stdio.h>
union ch1 { char c; short l; long s; };
int main(void)
{
	union ch1 u;
	printf("size of u is %d\n", sizeof(u));
	return 0;
}
