#include<stdio.h>
void bubble_sort(int a[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
			for(k=0;k<n;k++){
				printf("%d  ",a[k]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
}
int main(void)
{
	int a[10],i;
	printf("please input the numbers:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble_sort(a,10);
	return 0;
}

