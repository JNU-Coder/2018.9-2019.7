#include<stdio.h>//冒泡法排序 
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
	for(i=0;i<n-1;i++)//n个数，做n-1轮排序处理 
	{
		for(j=0;j<n-i-1;j++)//每轮做n-i次相邻数组元素的比较 
		if(a[j]>a[j+1])//顺序不符时交换位置 
		    t=a[j],a[j]=a[j+1],a[j+1]=t;//进行交换 
		for (k=0;k<n;k++)
		    printf("%d\n",a[k]);
		printf("\n");
	}
}
