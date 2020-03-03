#include<stdio.h>
int main(void)
{
	int i,j;
	int s[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int *p[3];//表示每一行的首地址； 
	p[0]=s[0];
	p[1]=s[1];
	p[2]=s[2];//赋初值 
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%5d",*(p[i]+j));
		}
		printf("\n");
	}
	return 0;//打印数组s第i行的元素； 
 } 
