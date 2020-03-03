#include<stdio.h>
#define n 5
struct stu{
	int a[n];
	char name[n];
};
int main(void)
{
	struct stu st1;
	int i,j,p,q,s;
	for(i=0;i<n;i++)
	{
		scanf("%c",&st1.name[i]);
		scanf("%d",&st1.a[i]);
	}
	for(i=0;i<n;i++)
	{
		p=i;q=st1.a[i];
		for(j=i+1;j<n;j++)
		{
			if(q<st1.a[j])
			{
				p=j;
				q=st1.a[j];
			}
		}
		if(i!=p)
			{
				s=st1.a[i];
				st1.a[i]=st1.a[p];
				st1.a[p]=s;
			}
		printf("%d\t",st1.a[i]);
	}
	return 0;
}
