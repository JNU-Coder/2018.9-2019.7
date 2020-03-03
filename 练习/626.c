#include<stdio.h>
int main(void)
{
	int s;
	scanf("%d",&s);
	while(s>0)
	{
		switch(s){
		case 1:printf("%d",s+5);break;
		case 2:printf("%d",s+4);break;
		case 3:printf("%d",s+3);break;
		default:printf("%d",s+1);break;
		}
		scanf("%d",&s);
	}
} 
