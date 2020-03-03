#include<stdio.h>
int main(void)
{
	char *s[]={"sunday","monday","tuesday","wednsday","thursday","friday","saturday"};
	int day;
	scanf("%d",&day);
	if(day>=0&&day<=6)
		puts(s[day]);
	else
		puts("input error!\n");
	return 0;
}
