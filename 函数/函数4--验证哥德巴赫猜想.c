#include<stdio.h>
bool analyse(int);
bool prime(int);
int main(void)
{
	int n;
	printf("please input 'n':\n");
	scanf("%d",&n);
	while(n>0){
		if(analyse(n))
		printf("\n-yes-\n");
		else
		printf("\n-no-\n");
		printf("please input n:\n");
		scanf("%d",&n);
	}
	return 0;
}
bool analyse(int n){
	int c;
	bool flag;
	flag=false;
	for(c=n-2;c>=n/2;c--){
		if(prime(c)&&prime(n-c)){
			printf("%d=%d+%d\n",n,c,n-c);
			flag=true;
		}
	}
	return flag;
}
bool prime(int n){
	int j;
	for(j=n/2;j>=2;j--){
		if(n%j==0) 
		return false;
	}
	return true;
}








