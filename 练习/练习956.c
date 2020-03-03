#include<stdio.h>
int ysfdg ( int sum, int value, int n)//sum为总人数，value为每次报的最大的数，n为第n次出局的人的编号； 
{
    if ( n == 1 )
        return ( sum + value - 1 ) %sum;
    else
        return ( ysfdg ( sum-1, value,n-1 ) +value ) %sum;//递归算法 
}
int main(void)
{
	int sum,value,n;
	printf("plaese input the conditions:\n");
	scanf("%d%d%d",&sum,&value,&n); 
	int c=0;
	c=ysfdg(sum,value,n);
	printf("%d\n",c);
	return 0;
} 
 
