void delete_(char s[],char c)
{
	int j=0,k=0;
	while (s[j]!='\0'){
		if(s[j]!=c)
		   s[k++]=s[j];
		j++;
	}
	s[k]='\0';
}
