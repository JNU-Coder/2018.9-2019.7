#include<stdio.h>
#include<math.h>
int main(void)
{
	long A,N,i;
	long sum=0,temp;
	printf("please input A and N:\n");
	if((A<=9)&&(A>=1)&&(N>=0)&&(N<=100000))
		scanf("%ld,%ld",&A,&N);
	else printf("input error!\n");
	for(i=0,temp=A;i<N;i++){
		sum+=temp;
		temp=temp+A*(pow(10,i+1));
	}
	printf("%ld\n",sum);
	return 0;
} 




















