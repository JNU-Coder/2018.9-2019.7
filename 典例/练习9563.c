#include<stdio.h>
int main(void)
{
  long long A,N,i,X=1,T=0,S=0;
  printf("please input A&N:\n");
  scanf("%lld%lld",&A,&N);
  for(i=0;i<N;i++)
  {
    T+=A*X;
    X*=10;
    S+=T;
  }
  printf("%llld\n",S);
  return 0;
} 
