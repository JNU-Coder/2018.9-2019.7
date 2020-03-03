#include<stdio.h>
char *strstr(char *s,char *t){
	char *ps=s,*pt,*pc;//*s为源串，t为字串； 
	while(*ps!='\0'){//*ps指向源串 
		for(pt=t,pc=ps;*pt!='\0'&&*pt==*pc;pt++,pc++)//*ps依次指向源串中的每一个字符;若源串字符与字串字符匹配且没到字符串尾，继续循环 
			if(*pt=='\0') return ps;//到字符串尾，说明匹配成功，返回字串出现的位置； 
			ps++;//*ps指向源串中的下一个字符； 
	}
	return 0;
}
int main(void)
{
	char s1[]="abcdefghijk",s2[]="fgh",*p;
	p=strstr(s1,s2);
	printf("%p\t%s\n",&s1[0],s1);//%p即指针类型 
	printf("%p\t%s\n",p,p);
	return 0;
}
