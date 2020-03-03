#include<stdio.h>
long pow(long m,long n){
	long p=1;
	long i;
	for(i=0;i<n;i++)
		p*=m;
	return p;
} 
int main(void)
{
	long x,y,z;
	printf("please input x&y:\n");
	scanf("%ld,%ld",&x,&y);
	z=pow(x,y);
	printf("%ld\n",z);
	return 0;
}
