char*strcat (char t[],char s[])
{
	int j=1,k=0;
	while(t[j++]!='\0');
	    j--;
	while((t[j++]=s[k++]));
	return t;
 } 
