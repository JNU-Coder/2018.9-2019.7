#include<stdio.h>//��֪�������������������� 
float a(int n,int v1,int v2,int v3,int v4,...)//�ɱ�����б������ں��� 
{
	float sum=v1;
	if(n>=2)sum+=v2;
	if(n>=3)sum+=v3;
	if(n>=4)sum+=v4;
	return sum/n;
}
int main(void)
{
	float a(int n,int v1,int v2,int v3,int v4,...);
	int v1=1,v2=2,v3=6,v4=0,v5=9;
	printf("%f\n",a(4,v1,v2,v3,v4,6));
	return 0;
}
