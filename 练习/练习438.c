#include<stdio.h>
#include<string.h>
#include<conio.h>//���� 
int main(void)
{
	char messege[100];
	char name[100];
	int i;
	printf("please input user's name:");
	for (i = 0; i < 100; i++)
	{
		name[i] = getch();
		if (name[i] == '\08')
		{
			name[i]='\0';
			i--;
		}
		if (name[i] == '\r')//"/r"Ϊ����"/t"Ϊ�س���������	
		{
			name[i]='\0';
			break;
		}
		if(name[i]!='\0') printf("*");
	}
	putchar('\n');
	strcat(messege, "hello ");
	strcat(messege, name);
	strcat(messege, ",how are you going?");
	printf("%s\n", messege);
}
