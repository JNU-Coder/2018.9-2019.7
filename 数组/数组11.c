#include<stdio.h>
int main(void)
{
	int s[8],i,j,k;
	printf("please input eight numbers!\n");
	for(i=0;i<8;i++)
		scanf("%d",&s[i]);
	for(i=0;i<7;i++){
		for(j=i+1;j<8;j++)
			if(s[i]>s[j]){
				k=s[i];
				s[i]=s[j];//�������ּ���   
				s[j]=k;
			}
	}
	printf("�źõ������ǣ�\n");
	for(i=0;i<8;i++)
	printf("%d\t",s[i]);
	return 0;
 } 
