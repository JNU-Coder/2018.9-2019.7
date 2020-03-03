#include<stdio.h>
#define N 10
int main(void)
{
	int s[N],i,j,k,t;
	for(i=0;i<N;i++)scanf("%d",&s[i]);
	for(i=0;i<N-1;i++){
		for(j=0;j<N-1-i;j++){
			if(s[j]>s[j+1]){
				t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
			printf("%d\n",s[i]);
		}
	}
	printf("the sorted numbers are :\n");
	for(i=0;i<N;i++)printf("%d\n",s[i]);
	return 0;
} 
