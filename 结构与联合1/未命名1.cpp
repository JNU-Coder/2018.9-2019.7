#include<stdio.h>
int main(void)
{
	int a,b,c,max;
	printf("please input    \n");
	scanf("%d,%d,%d",&a,&b,&c);
	max=a;
	if(c>b){
		if(b>a)max=c;
		else{if(c>a)max=c;
		}
	}
	else {
		if(b>a)max=b;
	}
	printf("%d\n",max);
 } 
