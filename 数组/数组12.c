#include<stdio.h>
int main(void)
{
	int s[8],i,j,k,z;
	printf("please input eight numbers!\n");
	for(i=0;i<8;i++)
		scanf("%d",&s[i]);
	for(i=0;i<7;i++)
	{
		k=i;//�洢��СԪ�ص��±� 
		for(j=i+1;j<8;j++)
			if(s[k]>s[j])
				k=j;//��¼��СԪ�ص��±� ������СԪ�ص��±겻ΪI 
			if(k!=i){
				z=s[i];
				s[i]=s[k];
				s[k]=z;//���ݽ��� 
			}
	}
	printf("�źõ�����Ϊ��\n");
	for (i=0;i<8;i++) 
	printf("%d\t",s[i]);
	return 0;
 }  
