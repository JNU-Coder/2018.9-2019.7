#include<stdio.h>
void s(int a,int b){
	printf("date=%d\n",a+b);
}
int main(void)
{
	int x,y;
	printf("please input tow numbers:\n");
	scanf("%d,%d",&x,&y);
	s(x,y);
	return 0;
}

