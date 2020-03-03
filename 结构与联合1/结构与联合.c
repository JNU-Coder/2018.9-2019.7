#include<stdio.h>
struct date{
	int year;
	int month;
	int day;
};
struct stud{
	char no[10];
	char name[20];
	struct date birthday;
	float score;
};
int main(void)
{
	struct stud stu1,stu2;
	printf("enter the first student¡¯s info:\n");
	gets(stu1.no);
	gets(stu1.name);
	scanf("%d%d%d",&stu1.birthday.year,&stu1.birthday.month,&stu1.birthday.day);
	scanf("%f",&stu1.score);
	getchar();
	printf("enter the second student¡¯s info:\n");
	gets(stu2.no);
	gets(stu2.name);
	scanf("%d%d%d",&stu2.birthday.year,&stu2.birthday.month,&stu2.birthday.day);
	scanf("%f",&stu2.score);
	puts("\nthe higher student:");
	if(stu1.score>=stu2.score){
		puts(stu1.no);
		puts(stu1.name);
		printf("%d-%d-%d\n",stu1.birthday.year,stu1.birthday.month,stu1.birthday.day);
		printf("%f",stu1.score);
	}
	else
	{
		puts(stu2.no);
		puts(stu2.name);
		printf("%d-%d-%d\n",stu2.birthday.year,stu2.birthday.month,stu2.birthday.day);
		printf("%f",stu2.score);
	}
	return 0;
}
