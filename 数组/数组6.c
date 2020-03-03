#include<stdio.h>
int main(void)
{
	int m,n,c,s[5][2],l[5][11];
	for(m=0;m<5;m++){
		for(n=0;n<2;n++)
		scanf("%d",&s[m][n]);
	}
	for(m=0;m<5;m++){
		for(n=0;n<11;n++)
		l[m][n]=0;
	}
	for(n=0;n<2;n++){
		for(m=0;m<5;m++){
		c=s[m][n]/10;
		l[m][c]++;
		}
	}
	for(m=0;m<5;m++){
		for(n=0;n<11;n++)
		printf("%d\t",l[m][n]);
	}	
 } 
