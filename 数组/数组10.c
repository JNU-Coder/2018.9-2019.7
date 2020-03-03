#include<stdio.h>
int main(void)
{
	int s[10]={12,32,65,55,22,95,5,21,54,55},i,guess;
	printf("please input the number you have guessed:\n");
	scanf("%d",&guess);
	for(i=0;i<10;i++)
		if(s[i]==guess)
		break;
		if(i<10)	
		printf("you guess it! it is the %d number!\n",i+1);
		else 
		printf("you do not guess it!");
	return 0;	
} 
