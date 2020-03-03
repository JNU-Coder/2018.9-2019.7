#include<stdio.h>
int s(int a,int b){
	return(a+b);
}
int main(void)
{
	int x,y,z;
	printf("please input x&y:\n");
	scanf("%d,%d",&x,&y);
	s(x,y);
	printf("%d",s(x,y));
	return 0;
}
