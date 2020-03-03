#include <stdio.h>
#define N 5
struct Database
{
	char name[10];
	char ID[12];
	char sex[8];
	int cls;
	char address[50];
	char tel[12];
	int score;
}student[N];
void resort(struct Database sp[]);


int main()
{
	int i = 0;
	for (; i < N; i++)
	{
		printf("\nThis is No.%d student:\n", i + 1);
		printf("# Name      ID      Sex      Class      Address      Telephone      Score\n");
		scanf("%s %s %s %d %s %s %d", student[i].name, student[i].ID, student[i].sex,  &student[i].cls, student[i].address,  student[i].tel, &student[i].score);
		printf("\nPlease confirm:\nName:%s\nID:%s\nSex:%s\nClass:%d\nAddress:%s\nTelephone:%s\nScore:%d\n", student[i].name, student[i].ID,  student[i].sex, student[i].cls, student[i].address,  student[i].tel, student[i].score);
	}
	resort(student);
	printf("\nRANK: ");
	for (i = 0; i < N; i++)
		printf("\nNo.%d is %s with the score of %d\n", i+1,student[i].name, student[i].score);
	return 0;
}

void resort(struct Database sp[])
{
	int i, j, p, q;
	struct Database s;
	for (i = 0; i < N; i++)
	{
		p = i;
		q = sp[i].score;
		for (j = i + 1; j < N; j++)
			if (q < sp[j].score)
			{
				p = j; q = sp[j].score;
			}
		if (i != p)
		{
			s = sp[i];
			sp[i] = sp[p];
			sp[p] = s;
		}
	}
}

