int trim(char s[])
{
	int i,num,j=0,k=0,l=strenlen(s);
	while(s[j]==' '||s[j]=='\t'||s[j]==\n||s[j]=='\r')
	    j++;
	i=i-1;
	while(s[i-k]==' '||s[i-k]=='\t'||s[i-k]=='\n'||s[i-k]=='\r')
	    k++;
	num=1-j-k;
	for(i=0;i<num;i++)
	    s[i]=s[i+j]
	s[num]='\0';
	return strlen(s);
 }
 int strlen(char s[])
{
	int j=0;
	while(s[j]!='\0') j++;
	return j;
}  
