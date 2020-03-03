//x?y?????y?z?????cheng¾ØÕóµÄ³Ë·¨Ö¸Õë°æ 
#include<stdio.h>
void matrix_multiply(int *m1, int *m2, register int *r, int x, int y, int z)
{
	register int *m1p;
	register int *m2p;
	register int k;
	int row;
	int column;
	/*??????????????????,?????????,????????*/
	for (row = 0; row < x; row += 1)
	{
		for (column = 0; column < z; column += 1)
		{
			//????????,????????m1?m2???;
			m1p = m1 + row * y;
			m2p = m2 + column;
			*r = 0;
			for (k = 0; k < y; k += 1)
			{
				*r += *m1p**m2p;
				m1p += 1;
				m2p += z;
			}
			//r ????,???????
			r++;
		}
	}
}
int main(void)
{
	int x=2, y=3, z=2;
	int i, j;
	int m1[2][3], m2[3][2], r[2][2] = { 0 };
	printf("please input A:\n");
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			scanf("%d", &m1[i][j]);
	printf("please inpur B:\n");
	for (i = 0; i < y; i++)
		for (j = 0; j < z; j++)
			scanf("%d", &m2[i][j]);
	matrix_multiply(&m1[0][0], &m2[0][0], &r[0][0], 2, 3, 2);
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < z; j++)
		{
			printf("%d\t", r[i][j]);
		}
		printf("\n");
	}
	return 0;
}
