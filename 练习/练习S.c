#include<stdio.h>//ͳ��10�����������ĸ�����������ƽ��ֵ 
int main(void)
{
	int i,j,k,x;
	printf("please input 10 numbers:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&x);
		if(x>0)
		{
			j+=x;
			++k;
		}	
	}
	if(k)
	printf("numbers=%d.average=%f\n",k,1.0*j/k);
	return 0;
} 
