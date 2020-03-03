#include<stdio.h>
int main(void)
{
	int a=0x1A;
	a=a>>3;//将左操作数向左（右）移动右操作数个位 
	printf("%x\n",a);
} 
