#include<stdio.h>
char *strstr(char *s,char *t){
	char *ps=s,*pt,*pc;//*sΪԴ����tΪ�ִ��� 
	while(*ps!='\0'){//*psָ��Դ�� 
		for(pt=t,pc=ps;*pt!='\0'&&*pt==*pc;pt++,pc++)//*ps����ָ��Դ���е�ÿһ���ַ�;��Դ���ַ����ִ��ַ�ƥ����û���ַ���β������ѭ�� 
			if(*pt=='\0') return ps;//���ַ���β��˵��ƥ��ɹ��������ִ����ֵ�λ�ã� 
			ps++;//*psָ��Դ���е���һ���ַ��� 
	}
	return 0;
}
int main(void)
{
	char s1[]="abcdefghijk",s2[]="fgh",*p;
	p=strstr(s1,s2);
	printf("%p\t%s\n",&s1[0],s1);//%p��ָ������ 
	printf("%p\t%s\n",p,p);
	return 0;
}
