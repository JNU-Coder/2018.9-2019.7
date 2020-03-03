#include<stdio.h>
void h(int n)//±ù±¢Êý 
{
	int i,v;
	printf("please input n:\n");
	scanf("%d",&n);
	for(i=0,v=1;;i++)
	{
		if((n%2)==0)
		{
			n=n/2;
			printf("%d\t",n);
			v++;
		}
		else 
		{
			n=3*n+1;
			printf("%d\t",n);
			v++;
		}
		if(n==1)
		{
			printf("\n");
			printf("all is %d numbers!\n",v);
			break;
		}
	}
	return i;
}
int main(void)
{
	int n,v;
	h(n);
	return 0;
}
