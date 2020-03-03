#include<stdio.h>
int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	return (z);
}
int main(void)
{
	int x,y;
	printf("please input x&y:\n");
	scanf("%d%d",&x,&y);
	printf("%c\n",printf("%d\n",max(x,y)));
	return 0;
}
