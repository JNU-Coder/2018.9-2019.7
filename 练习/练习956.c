#include<stdio.h>
int ysfdg ( int sum, int value, int n)//sumΪ��������valueΪÿ�α�����������nΪ��n�γ��ֵ��˵ı�ţ� 
{
    if ( n == 1 )
        return ( sum + value - 1 ) %sum;
    else
        return ( ysfdg ( sum-1, value,n-1 ) +value ) %sum;//�ݹ��㷨 
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
 
