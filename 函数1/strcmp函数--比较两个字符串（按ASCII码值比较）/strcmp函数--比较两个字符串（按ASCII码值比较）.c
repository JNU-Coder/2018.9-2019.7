int strcmp(char s[],char t[])
{
	int j=0;
	while(s[j]==t[j]&&s[j]!='\0')
	j++;
	return s[j]-t[j];
 } 
