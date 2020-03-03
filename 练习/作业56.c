#include<stdio.h>
#include<string.h>
void mystrcat(char *p1,char *p2)
{
	int i,t=strlen(p2);
	for(i=0;i<strlen(p1);i++)
	{
		*(p2+t)=*(p1+i);
		t++;	
	}	
}
int main(void)
{
	char s[100],a[200];
	printf("please inpiut s[]:\n");
	gets(s);
	printf("please input a[]:\n");
	gets(a); 
	mystrcat(s,a);
	printf("%s\n",a);
	return 0;
}
