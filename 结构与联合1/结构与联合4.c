#include<stdio.h>//学生成绩统计（非指针版）； 
#define N 5
struct student{
	char no[10];
	char name[10];
	float score[3];
	float total;
};
int main(void)
{
	struct student stu[N];
	struct student temp;
	int i,j,k;
	puts("输入学生信息:\n");
	for(i=0;i<N;i++){
		printf("student #%d:\n",i+1);
		gets(stu[i].no);
		gets(stu[i].name);
		scanf("%f%f%f",&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		getchar();
		stu[i].total=stu[i].score[1]+stu[i].score[0]+stu[i].score[2];
	}
	for(i=0;i<N-1;i++){
		k=i;
		for(j=k+1;j<N;j++){
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
	printf("\n成绩单:\n");
	printf("%-12s%-22s%-10s%-10s%-10s%-10s\n","no","name","c","math","english","total");
	for(i=0;i<N;i++){
		printf("%-12s%-22s",stu[i].no,stu[i].name);
		printf("%-10.1f%-10.1f%-10.1f",stu[i].score[0],stu[i].score[1],stu[i].score[2]);
		printf("%-10.1f\n",stu[i].total);
	}
	return 0;
}





































