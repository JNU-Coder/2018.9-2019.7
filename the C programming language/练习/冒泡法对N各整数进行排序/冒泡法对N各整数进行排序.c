#include<stdio.h>//ð�ݷ����� 
void bubble_sort(int a[],int n);
int main(void)
{
	int x[6];
	int l;
	for(l=0;l<6;l++)
		scanf("%d",&x[l]);
	bubble_sort(x,6);
	return 0;
 } 
void bubble_sort(int a[],int n)
{
	int i,j,t,k;
	for(i=0;i<n-1;i++)//n��������n-1�������� 
	{
		for(j=0;j<n-i-1;j++)//ÿ����n-i����������Ԫ�صıȽ� 
		if(a[j]>a[j+1])//˳�򲻷�ʱ����λ�� 
		    t=a[j],a[j]=a[j+1],a[j+1]=t;//���н��� 
		for (k=0;k<n;k++)
		    printf("%d\n",a[k]);
		printf("\n");
	}
}
