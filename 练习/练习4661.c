#include<stdio.h>
void change(int b[])
{	int i,max,p,q,min;
	for(i=1;i<10;i++)
	{	max=b[0];
		if(max<b[i])
		{max=b[i];p=i;}
	}
	for(i=1;i<10;i++)
	{	min=b[0];
		if(min>b[i])
		{min=b[i];q=i;}
	}
	i=b[p];b[p]=b[q];b[q]=i;
}
int main()
{
	int a[10],i;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	change(a);
	for(i=0;i<10;i++)
		printf("%d\t",a[i]);
	return 0;
}

