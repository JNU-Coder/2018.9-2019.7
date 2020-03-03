#include<stdio.h>//Õ≥º∆÷∏’Î∞Ê 
#define N 5
struct student{
	char no[10];
	char name[10];
	int score[3];
	float total;
};
int main(void)
{
	struct student stu[N];
	struct student temp;
	struct student *p;
	p=&stu[0];
	int i,j,k;
	puts("enter the students's info:\n");
	for(i=0;i<N;p+=6,i+=6)
	{
		printf("student#:");
		scanf("%c",p);
		putchar('\n');
		printf("no:");
		scanf("%c",p+1);
		putchar('\n');
		printf("score math C English:");
		scanf("%d\n%d\n%d\n",p+2,p+3,p+4);
		putchar('\n');
	}
	for(i=0;i<N;i++)
	{
		k=i;
		for(j=i+1;j<N;j++){
			if(stu[j].total>stu[k].total)
			k=j;
			else if(stu[j].total==stu[k].total){
				if(stu[j].score[2]>stu[k].score[2])
				k=j;
			}
		}
		if(k!=i){
			temp=stu[i];
			stu[i]=stu[k];
			stu[k]=temp;
		}
	}
	printf("\nthe sort list:\n");
	printf("%-12s%-22s%-10ss%-10ss%-10ss%-10s\n","no","name","C","English","total");
	for(i=0;i<N;i+=6,p+=6){
		printf("%-12s%-22s",*p,*(p+1));
		printf("%-10.1f%-10.1f%-10.1f",*(p+2),*(p+3),*(p+4));
		printf("%-10.1f\n",*(p+5));
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
