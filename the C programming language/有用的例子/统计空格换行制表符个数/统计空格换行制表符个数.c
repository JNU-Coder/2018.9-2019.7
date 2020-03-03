#include<stdio.h>
int main()
{
	int i,nl,nm,nj;
	nl=0,nj=0,nm=0;
	while((i=getchar())!=EOF);
	{if (i==' ')
        ++nm;
    else if (i=='\t')
        ++nl;
    else if (i=='\n')
        ++nj;} 
    printf("%d %d %d\n",nl,nm,nj);
} 
