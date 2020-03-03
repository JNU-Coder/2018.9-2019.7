#include<stdio.h>
void r(int *s)
{
	int i=0, j=0, k=0, temp=0, max = s[0], min = s[0];
	for (i = 0; i < 10; i++)
	{
		if (s[i] >= max)
		{
			max = s[i];
			j = i;
		}
		if (s[i] <= min)
		{
			min = s[i];
			k = i;
		}
	}
    temp=s[j];
	s[j] = s[k];
	s[k] = temp;
}
int main(void)
{
	int i, s[10];
	printf("please input s[10]\n");
	for (i = 0; i < 10; i++) scanf("%d", &s[i]);
	r(s);
	for(i=0;i<10;i++)
	printf("%d\t", s[i]);
	return 0;
}
