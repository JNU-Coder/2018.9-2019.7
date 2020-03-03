#include<stdio.h>
int main(void)
{
	int a[8], *p, i, j, k, t;
	p = a;
	printf("input the numbers:");
	for (i = 0; i < 8; i++)
	{
		scanf("%d", p+i);
	}
	for (i = 0; i < 8; i++)
	{
		for (j = i; j < 8; j++)
		{
			if (j == i || *(p + j) < t)
			{
				t=*(p+j);
				k = j;
			}
		}
		if (k != i)
		{
			t = *(p + k);
			*(p + k) = *(p + i);
			*(p + i) = t;
		}
	}
	for (i = 0; i < 8; i++)
	{
		printf("%5d", *(p + i));
	}
	return 0;
}
