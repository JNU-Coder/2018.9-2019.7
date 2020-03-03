#include<stdio.h>
int main(void)
{
	int i, k = 0;
	char a[80], b[108], *p;
	p = a;
	gets(p);
	for (i = 1;i<=80; p++, k++, i++)
	{
		if (((i-1)%3==0)&&(i!=1))
		{
			b[k] = ' ';
			k++;
		}
		b[k] = *p;
	}
	b[k] = '\0';
	puts(b);
	return 0;
}
