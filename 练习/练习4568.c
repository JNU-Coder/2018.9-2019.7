#include<stdio.h>//��һ���ַ����г�ȥ����Ŀո� 
int main(void) 
{
	char s[100]={0},a[100]={0};
	int i,j,k,t;
	printf("please input the string :\n");
	gets(s);
	/*���Կո�������Իس���������ʹ��gets() ;�Իس���ո������
	����scanf��"%s",s);�����鳤�Ƚ�������ʹ��scanf("%c",&s[i]); */
	for(i=0,j=0,k=0;i<100;i++)
	{
		k=0;
		if(s[i]==' ')
		for(t=i;s[t]==' ';t++)
		{
			k++;
		}
		if(k>1)
		{
			i=t-1;
			a[j]=' ';
			j++;
		}
		else
		{
			a[j]=s[i];
			j++;
		}
	} 
	for(i=0;i<100;i++) printf("%c",a[i]);
	printf("\n");
	return 0;
}
