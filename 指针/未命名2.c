#include<stdio.h>
int main()
{
	int s[5][2], i,j=0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &s[i][j]);
	}
	for (i = 0; i < 5; i++)
		for (j = 0; j < 2; j++)
			printf("%d", s[i][j]);
	return 0;
}

