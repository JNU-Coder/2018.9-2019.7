#include<stdio.h>
#include<string.h>
int  hws(char *string)
{
	int i, j = strlen(string), k;
	for (i = 0,k = j-1; i <= (j / 2); )
	{
		if (string[i] == string[k])
		{
			i++;
			k--;
			continue;
		}
		else break;
	}
	if (i>=(j/2.0)){
		printf("it is a ???\n");return 1;
	}
	else {
		printf("it is not a ???\n"); return 0;
	}
}
int main(void)
{
	char string[5][50];int i,0j=0;
	printf("please input string:\n");
	for(i=0;i<5;i++){
		scanf_s("%s", string[i]);
		j=j+hws(string[i]);
	}
	printf("%d\n",j);
	return 0;
}
