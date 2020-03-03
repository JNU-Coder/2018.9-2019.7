#include<stdio.h>
#include<math.h>
void wa(unsigned int amount,char *buffer)
{
	int i = 1, j = 0,m,s[10],temp=0,l,s1000=0,s100=0,s10=0,s1=0;
	unsigned k = amount;
	while (k / 10 != 0)
	{
		k /= 10;
		i++;
	}
	l = i;
	for (m=0; j < i; j++)
	{
		m = pow(10, i);
		temp = amount % m;
		i--;
		if (temp >= 0)s[i]++;
		else break;
	}
	for (i=1;i<=l;i++)
	{
		if (i >= 4)s1000 = s[i] * pow(10, i - 3)+s1000;
		if (i == 3)s100 = s[i];
		if (i == 2)s10 = s[i];
		if (i == 1)s1 = s[i];
	}
	switch (s1000)
	{
	case 1:printf("one"); break;
	case 2:printf("two"); break;
	case 3:printf("three"); break;	
	case 4:printf("four"); break;
	case 5:printf("five"); break;
	case 6:printf("six"); break;
	case 7:printf("secen"); break;
	case 8:printf("eight"); break;
	case 9:printf("nine"); break;
	case 10:printf("ten"); break;
	case 11:printf("eleven"); break;
	case 12:printf("twelve"); break;
	case 13:printf("thirteen"); break;
	case 14:printf("fourteen"); break;
	case 15:printf("fifteen"); break;
	case 16:prinf("sixteen"); break;
	case 17:printf("seventeen"); break;
	case 18:printf("eighteen"); break;
	case 19:printf("ninteen"); break;
	case 20:printf("twenty"); break;
	default :
		{
			int i = 0;
			i = s1000 % 100;
			switch (i) 
			{
			case 1:printf("one"); break;
			case 2:printf("two"); break;
			case 3:printf("three"); break;
			case 4:printf("four"); break;
			case 5:printf("five"); break;
			case 6:printf("six"); break;
			case 7:printf("secen"); break;
			case 8:printf("eight"); break;
			case 9:printf("nine"); break;
			case 10:printf("ten"); break;
			}
			switch (i)
			{
			case 1:printf("one"); break;
			case 2:printf("two"); break;
			case 3:printf("three"); break;
			case 4:printf("four"); break;
			case 5:printf("five"); break;
			case 6:printf("six"); break;
			case 7:printf("secen"); break;
			case 8:printf("eight"); break;
			case 9:printf("nine"); break;
			case 10:printf("ten"); break;
			}
		}
	}
};
int main(void)
{
	unsigned int amount;
	char *buffer=NULL;
	printf("please input amount:\n");
	scanf_s("%ul", &amount);
	wa(amount, buffer);
	return 0;
}