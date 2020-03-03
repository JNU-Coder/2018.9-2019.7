#include<stdio.h>
#include<ctype.h>
#define number 100
int getint(int *pn){
	int c,sign;
	while(isspace(c=getchar()));
	if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
		printf("input error!\n");
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='+'||c=='-')c=getchar();
	for(*pn=0;isdigit(c);c=getchar())
	*pn=10**pn+(c-'0');
	return c;
}
int main(void)
{
	int a[number],i,j,k;
	printf("input integers ends with enter\n");
	for(i=0;i<number&&(k=getint(&a[i]))!='\n';)
		if(k) i++;
	for(j=0;j<=i;j++)
	{
		printf("%d",&a[j]);
	}
	printf("\n");
	return 0;
}
