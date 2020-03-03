#include<stdio.h>
#include<string.h>
int main(void)
{
	char name[10][15];
	char *p[10];
	char *temp;
	int i,j,k;//Ã»ÓÐÅª¶® £¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡11 
	printf("enter the names of 10 students:\n");
	for(i=0;i<10;i++){
		gets(name[i]);
		p[i]=name[i];
	}
	for(i=0;i<9;i++)
	{
		k=i;
		for(j=i+1;j<10;j++)
			if(strcmp(p[j],p[k]<0))k=j;
			if(k!=i){
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}
	}
	printf("\nthe sorted result is :\n");
	printf("---------------------------");
	for(i=0;i<10;i++)
	puts(p[i]);
	return 0;
}
