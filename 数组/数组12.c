#include<stdio.h>
int main(void)
{
	int s[8],i,j,k,z;
	printf("please input eight numbers!\n");
	for(i=0;i<8;i++)
		scanf("%d",&s[i]);
	for(i=0;i<7;i++)
	{
		k=i;//存储最小元素的下标 
		for(j=i+1;j<8;j++)
			if(s[k]>s[j])
				k=j;//记录较小元素的下标 ，即最小元素的下标不为I 
			if(k!=i){
				z=s[i];
				s[i]=s[k];
				s[k]=z;//数据交换 
			}
	}
	printf("排好的序列为：\n");
	for (i=0;i<8;i++) 
	printf("%d\t",s[i]);
	return 0;
 }  
